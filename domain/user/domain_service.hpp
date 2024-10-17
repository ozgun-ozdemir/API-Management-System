#ifndef DOMAIN_SERVICE_HPP
#define DOMAIN_SERVICE_HPP

#include "repository.hpp"
#include "user.hpp"


using namespace std;

namespace DomainService {
    inline void addUser(const string& name, const string& surname, const string& phone, const string& email, const string& address, pqxx::work& W) {
        const User user{name, surname, phone, email, address};
        Repository::addUser(user, W);
    }

    inline void updateUser(const int id, const string& name, const string& surname, const string& phone, const string& email, const string& address, pqxx::work& W) {
        User user{name, surname, phone, email, address};
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
