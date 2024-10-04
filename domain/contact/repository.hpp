#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <pqxx/pqxx>
#include "contact.hpp"
#include "factory.hpp"
#include <crow.h>

using namespace std;

namespace Repository {
    inline void addContact(const Contact& contact, pqxx::work& W) {
        W.exec("INSERT INTO contacts (name, surname, phone_number, email, notes) VALUES ("
                + W.quote(contact.name) + ", "
                + W.quote(contact.surname) + ", "
                + W.quote(contact.phone_number) + ", "
                + W.quote(contact.email) + ", "
                + W.quote(contact.notes) + ")");
    }

    inline void updateContact(const Contact& contact, pqxx::work& W) {
        W.exec("UPDATE contacts SET name = " + W.quote(contact.name) + ", "
                "surname = " + W.quote(contact.surname) + ", "
                "phone_number = " + W.quote(contact.phone_number) + ", "
                "email = " + W.quote(contact.email) + ", "
                "notes = " + W.quote(contact.notes) + " "
                "WHERE id = " + to_string(contact.id));
    }

    inline void deleteContact(const int id, pqxx::work& W) {
        W.exec("DELETE FROM contacts WHERE id = " + to_string(id));
        W.commit();
    }

    // Todo vector contact tipinde dönüş yapılacak
    inline vector<Contact> listContacts(pqxx::connection& dbConnection) {
        pqxx::nontransaction N(dbConnection);
        const pqxx::result result = N.exec("SELECT id, name, surname, phone_number, email, notes FROM contacts");
        return ContactFactory::createFromResult(result);
    }

}

#endif