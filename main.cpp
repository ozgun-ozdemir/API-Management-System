#include <crow.h>
#include <pqxx/pqxx>
#include <iostream>

#include "../infrastructure/infrastructure.hpp"
#include "product/application_service.hpp"
#include "user/application_service.hpp"
#include "order/application_service.hpp"


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

//user

    CROW_ROUTE(app, "/users").methods("GET"_method)([]() {
        pqxx::connection& dbConnection = getDatabaseConnection();
        return ApplicationServer::listUsers(dbConnection);
    });

    CROW_ROUTE(app, "/users/add").methods("POST"_method)([](const crow::request& req) {
        pqxx::connection& dbConnection = getDatabaseConnection();
        pqxx::work W(dbConnection);
        auto json = crow::json::load(req.body);
        if (!json) {
            return crow::response(400, "Invalid JSON");
        }

        string name = json["name"].s();
        string surname = json["surname"].s();
        string phoneNumber = json["phone_number"].s();
        string email = json["email"].s();
        string address = json["address"].s();

        try {
            ApplicationServer::addUser(W, name, surname, phoneNumber, email, address);
            W.commit();
            return crow::response(201, "User added successfully!");

        } catch (const exception& e) {
            logError(e.what());
            W.abort();
            return crow::response(500, e.what());
        }
    });

    CROW_ROUTE(app, "/users/update").methods("POST"_method)([](const crow::request& req) {
        pqxx::connection& dbConnection = getDatabaseConnection();
        pqxx::work W(dbConnection);
        auto json = crow::json::load(req.body);
        if (!json) {
            return crow::response(400, "Invalid JSON");
        }
        int id = json["id"].i();
        string name = json["name"].s();
        string surname = json["surname"].s();
        string phoneNumber = json["phone_number"].s();
        string email = json["email"].s();
        string address = json["address"].s();

        try {
            ApplicationServer::updateUser(W, id, name, surname, phoneNumber, email, address);
            W.commit();
            return crow::response(200, "User updated successfully!");
        } catch (const exception& e) {
            logError(e.what());
            W.abort();
            return crow::response(500, e.what());
        }
    });

    CROW_ROUTE(app, "/users/delete").methods("DELETE"_method)([](const crow::request& req) {
        pqxx::connection& dbConnection = getDatabaseConnection();
        pqxx::work W(dbConnection);
        const auto json = crow::json::load(req.body);
    if (!json) {
        return crow::response(400, "Invalid JSON");
    }
        const int id = json["id"].i();

        try {
            ApplicationServer::deleteUser(id, W);
            W.commit();
            return crow::response(200, "User deleted successfully!");
        } catch (const exception& e) {
            logError(e.what());
            W.abort();
            return crow::response(500, e.what());
        }
    });

//product

    CROW_ROUTE(app, "/products").methods("GET"_method)([]() {
        pqxx::connection& dbConnection = getDatabaseConnection();
        return ApplicationServer::listProducts(dbConnection);
    });

    CROW_ROUTE(app, "/products/add").methods("POST"_method)([](const crow::request& req) {
            pqxx::connection& dbConnection = getDatabaseConnection();
            pqxx::work W(dbConnection);
            auto json = crow::json::load(req.body);
            if (!json) {
                return crow::response(400, "Invalid JSON");
            }

            string name = json["name"].s();
            string price = json["price"].s();
            string quantity = json["quantity"].s();

            try {
                ApplicationServer::addProduct(W, name, price, quantity);
                W.commit();
                return crow::response(201, "Product added successfully!");

            } catch (const exception& e) {
                logError(e.what());
                W.abort();
                return crow::response(500, e.what());
            }
        });
        CROW_ROUTE(app, "/products/update").methods("POST"_method)([](const crow::request& req) {
        pqxx::connection& dbConnection = getDatabaseConnection();
        pqxx::work W(dbConnection);
        auto json = crow::json::load(req.body);
        if (!json) {
            return crow::response(400, "Invalid JSON");
        }
        int id = json["id"].i();
        string name = json["name"].s();
        string price = json["price"].s();
        string quantity = json["quantity"].s();

        try {
            ApplicationServer::updateProduct(W, id, name, price, quantity);
            W.commit();
            return crow::response(200, "Product updated successfully!");
        } catch (const exception& e) {
            logError(e.what());
            W.abort();
            return crow::response(500, e.what());
        }
    });

    CROW_ROUTE(app, "/products/delete").methods("DELETE"_method)([](const crow::request& req) {
            pqxx::connection& dbConnection = getDatabaseConnection();
            pqxx::work W(dbConnection);
            const auto json = crow::json::load(req.body);
        if (!json) {
            return crow::response(400, "Invalid JSON");
        }
            const int id = json["id"].i();

            try {
                ApplicationServer::deleteProduct(id, W);
                W.commit();
                return crow::response(200, "Product deleted successfully!");
            } catch (const exception& e) {
                logError(e.what());
                W.abort();
                return crow::response(500, e.what());
            }
        });

//order

    CROW_ROUTE(app, "/orders").methods("GET"_method)([]() {
    pqxx::connection& dbConnection = getDatabaseConnection();
    return ApplicationServer::listOrders(dbConnection);
});

    CROW_ROUTE(app, "/order").methods("POST"_method)([](const crow::request& req) {
        pqxx::connection& dbConnection = getDatabaseConnection();
        const auto json = crow::json::load(req.body);
      if (!json) {
          return crow::response(400, "Invalid JSON body");
      }

      const int id = json["id"].i();

        try {
            if (!id) {
           return crow::response(404, "Order not found");
       }
            return crow::response(ApplicationServer::getOrderById(id, dbConnection));

        } catch (const exception& e) {
            logError(e.what());
            return crow::response(500, e.what());
        }
  });

    CROW_ROUTE(app, "/orders/add").methods("POST"_method)([](const crow::request& req) {
    pqxx::connection& dbConnection = getDatabaseConnection();
    pqxx::work W(dbConnection);
    auto json = crow::json::load(req.body);
    if (!json) {
        return crow::response(400, "Invalid JSON");
    }

    const int userId = json["user_id"].i();
    const int productId = json["product_id"].i();

    try {
        ApplicationServer::addOrder(W, userId, productId);
        W.commit();
        return crow::response(201, "Order added successfully!");
    } catch (const exception& e) {
        W.abort();
        return crow::response(500, e.what());
    }
});

    CROW_ROUTE(app, "/orders/delete").methods("DELETE"_method)([](const crow::request& req) {
        pqxx::connection& dbConnection = getDatabaseConnection();
        pqxx::work W(dbConnection);
        const auto json = crow::json::load(req.body);
        if (!json) {
            return crow::response(400, "Invalid JSON");
        }
        int id = json["id"].i();

        try {
            ApplicationServer::deleteOrder(id, W);
            W.commit();
            return crow::response(200, "Order deleted successfully!");
        } catch (const exception& e) {
            W.abort();
            return crow::response(500, e.what());
        }
    });
    app.port(18081).multithreaded().run();
}