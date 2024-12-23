#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <pqxx/pqxx>
#include "user.hpp"
#include "factory.hpp"

using namespace std;

namespace Repository {
    inline void addUser(const User& user, pqxx::work& W) {
        W.exec_params("INSERT INTO users (name, surname, phone_number, email, address) VALUES ($1, $2, $3, $4, $5)",
            user.name, user.surname, user.phoneNumber, user.email, user.address);
    }

    inline void updateUser(const User& user, pqxx::work& W) {
        W.exec_params("UPDATE users SET name = $1, surname = $2, phone_number = $3, email = $4, address = $5 WHERE id = $6",
            user.name, user.surname, user.phoneNumber, user.email, user.address, user.id);
    }

    inline void deleteUser(const int id, pqxx::work& W) {
        W.exec_params("DELETE FROM users WHERE id = $1", to_string(id));
    }

    inline vector<User> listUsers(pqxx::connection& db_connection) {
        pqxx::nontransaction N(db_connection);
        const pqxx::result result = N.exec("SELECT id, name, surname, phone_number, email, address FROM users");
        return Factory::createUserFromResult(result);
    }
}

#endif
