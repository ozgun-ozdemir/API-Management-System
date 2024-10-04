#include <crow.h>
#include <pqxx/pqxx>
#include <iostream>
#include "../application/application_service.hpp"
#include "../infrastructure/infrastructure.hpp"

using namespace std;

inline pqxx::connection& getDatabaseConnection() {
    static pqxx::connection connection("dbname=postgres user=ozgun password=5432");
    if (!connection.is_open()) {
        throw runtime_error("Can't open database");
    }
    return connection;
}

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/contacts").methods("GET"_method)([]() {
        pqxx::connection& dbConnection = getDatabaseConnection();
        return ApplicationServer::listContacts(dbConnection);
    });

    CROW_ROUTE(app, "/contacts/add").methods("POST"_method)([](const crow::request& req) {
        pqxx::connection& dbConnection = getDatabaseConnection();
        pqxx::work W(dbConnection);
        auto json = crow::json::load(req.body);
        if (!json) {
            return crow::response(400, "Invalid JSON");
        }

        string name = json["name"].s();
        string surname = json["surname"].s();
        string phone_number = json["phone_number"].s();
        string email = json["email"].s();
        string notes = json["notes"].s();

        try {
            ApplicationServer::addContact(W, name, surname, phone_number, email, notes);
            W.commit();
            return crow::response(201, "Contact added successfully!");

        } catch (const exception& e) {
            logError(e.what());
            W.abort();
            return crow::response(500, e.what());
        }
    });

    CROW_ROUTE(app, "/contacts/update/<int>").methods("POST"_method)([](const crow::request& req, int id) {
        pqxx::connection& dbConnection = getDatabaseConnection();
        pqxx::work W(dbConnection);
        auto json = crow::json::load(req.body);
        if (!json) {
            return crow::response(400, "Invalid JSON");
        }

        string name = json["name"].s();
        string surname = json["surname"].s();
        string phone_number = json["phone_number"].s();
        string email = json["email"].s();
        string notes = json["notes"].s();

        try {
            ApplicationServer::updateContact(W, id, name, surname, phone_number, email, notes);
            W.commit();
            return crow::response(200, "Contact updated successfully!");
        } catch (const exception& e) {
            logError(e.what());
            W.abort();
            return crow::response(500, e.what());
        }
    });

    CROW_ROUTE(app, "/contacts/delete/<int>").methods("DELETE"_method)([](const int id) {
        pqxx::connection& dbConnection = getDatabaseConnection();
        pqxx::work W(dbConnection);
        try {
            ApplicationServer::deleteContact(id, W);
            W.commit();
            return crow::response(200, "Contact deleted successfully!");
        } catch (const exception& e) {
            logError(e.what());
            W.abort();
            return crow::response(500, e.what());
        }
    });

    app.port(18081).multithreaded().run();
}
