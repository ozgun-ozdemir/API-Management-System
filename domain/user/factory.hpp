#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "user.hpp"
#include <pqxx/pqxx>
#include <crow.h>

using namespace std;

namespace UserFactory {
    inline User create(const string& name, const string& surname, const string& phone, const string& email, const string& notes) {
        return User{name, surname, phone, email, notes};
    }

    inline vector<User> createFromResult(const pqxx::result& result) {
        vector<User> userList;

        for (const auto& row : result) {
            User user;
            user.id = row[0].as<int>();
            user.name = row[1].as<string>();
            user.surname = row[2].as<string>();
            user.phoneNumber = row[3].as<string>();
            user.email = row[4].as<string>();
            user.notes = row[5].as<string>();

            userList.push_back(user);
        }

        return userList;
    }
}

#endif
