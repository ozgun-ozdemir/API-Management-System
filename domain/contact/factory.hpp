#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "contact.hpp"
#include <pqxx/pqxx>
#include <crow.h>

using namespace std;

namespace ContactFactory {
    inline Contact create(const string& name, const string& surname, const string& phone, const string& email, const string& notes) {
        return Contact{-1, name, surname, phone, email, notes};
    }

    // Todo json dönülmeyecek
    inline vector<Contact> createFromResult(const pqxx::result &result) {
        vector<Contact> contactList;

        for (const auto& row : result) {
            Contact contact;
            contact.id = row[0].as<int>();
            contact.name = row[1].as<string>();
            contact.surname = row[2].as<string>();
            contact.phone_number = row[3].as<string>();
            contact.email = row[4].as<string>();
            contact.notes = row[5].as<string>();

            contactList.push_back(contact);
        }

        return contactList;
    }


}

#endif
