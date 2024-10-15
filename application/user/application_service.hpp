#ifndef APPLICATION_SERVER_HPP
#define APPLICATION_SERVER_HPP

#include "../domain/user/domain_service.hpp"
#include "user/dto_assembler.hpp"

using namespace std;

namespace ApplicationServer {
    inline void addUser(pqxx::work& W, const string& name, const string& surname, const string& phone, const string& email, const string& notes) {
        DomainService::addUser(name, surname, phone, email, notes, W);
    }

    inline void updateUser(pqxx::work& W, const int id, const string& name, const string& surname, const string& phone, const string& email, const string& notes) {
        DomainService::updateUser(id, name, surname, phone, email, notes, W);
    }

    inline void deleteUser(const int id, pqxx::work& W) {
        DomainService::deleteUser(id, W);
    }

    inline crow::json::wvalue listUsers(pqxx::connection& dbConnection) {
        const vector<User> users = DomainService::listUser(dbConnection);
        return DtoAssembler::toJson(users);
    }

}

#endif
