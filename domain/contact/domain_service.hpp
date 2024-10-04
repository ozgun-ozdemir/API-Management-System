#ifndef DOMAIN_SERVICE_HPP
#define DOMAIN_SERVICE_HPP

#include "repository.hpp"
#include "contact.hpp"
#include "factory.hpp"


using namespace std;

namespace DomainService {
    inline void addContact(const Contact& contact, pqxx::work& W) {
        Repository::addContact(contact, W);
    }

    inline void updateContact(const Contact& contact, pqxx::work& W) {
        Repository::updateContact(contact, W);
    }

    inline void deleteContact(const int id, pqxx::work& W) {
        Repository::deleteContact(id, W);
    }

    inline vector<Contact> listContacts(pqxx::connection& dbConnection) {
        pqxx::nontransaction N(dbConnection);
        const pqxx::result result = N.exec("SELECT id, name, surname, phone_number, email, notes FROM contacts");
        return ContactFactory::createFromResult(result);
    }
}

#endif
