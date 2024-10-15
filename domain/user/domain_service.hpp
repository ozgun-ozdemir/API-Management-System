#ifndef DOMAIN_SERVICE_HPP
#define DOMAIN_SERVICE_HPP

#include "repository.hpp"
#include "user.hpp"
#include "basket/basket.hpp"

using namespace std;

namespace DomainService {
    inline void addUser(const string& name, const string& surname, const string& phone, const string& email, const string& notes, pqxx::work& W) {
        const User user{name, surname, phone, email, notes};
        Repository::addUser(user, W);
    }

    inline void updateUser(const int id, const string& name, const string& surname, const string& phone, const string& email, const string& notes, pqxx::work& W) {
        User user{name, surname, phone, email, notes};
        user.id = id;
        Repository::updateUser(user, W);
    }

    inline void deleteUser(const int id, pqxx::work& W) {
        Repository::deleteUser(id, W);
    }

    inline vector<User> listUser(pqxx::connection& dbConnection) {
        return Repository::listUsers(dbConnection);
    }


}

#endif
