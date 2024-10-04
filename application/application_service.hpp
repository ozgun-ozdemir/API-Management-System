#ifndef APPLICATION_SERVER_HPP
#define APPLICATION_SERVER_HPP

#include "../domain/contact/domain_service.hpp"
#include "../application/dto-assembler.hpp"

using namespace std;

namespace ApplicationServer {
    inline void addContact(pqxx::work& W, const string& name, const string& surname, const string& phone, const string& email, const string& notes) {
        const Contact contact = ContactFactory::create(name, surname, phone, email, notes);
        DomainService::addContact(contact, W);
    }

    inline void updateContact(pqxx::work& W, const int id, const string& name, const string& surname, const string& phone, const string& email, const string& notes) {
        Contact contact = ContactFactory::create(name, surname, phone, email, notes);
        contact.id = id;
        DomainService::updateContact(contact, W);
    }

    inline void deleteContact(const int id, pqxx::work& W) {
        DomainService::deleteContact(id, W);
    }

    inline crow::json::wvalue listContacts(pqxx::connection& dbConnection) {
        const vector<Contact> contacts = DomainService::listContacts(dbConnection);
        return DtoAssembler::toJson(contacts);
    }
}

#endif
