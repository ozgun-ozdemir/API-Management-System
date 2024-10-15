#ifndef DTO_ASSEMBLER_HPP
#define DTO_ASSEMBLER_HPP

#include <crow/json.h>
#include <vector>
#include "user/user.hpp"

namespace DtoAssembler {

    inline crow::json::wvalue toJson(const vector<User>& users) {
        crow::json::wvalue::list userList;
        crow::json::wvalue jsonUser;

        for (const auto& [id, name, surname, phoneNumber, email, notes] : users) {
            jsonUser["id"] = id;
            jsonUser["name"] = name;
            jsonUser["surname"] = surname;
            jsonUser["phone_number"] = phoneNumber;
            jsonUser["email"] = email;
            jsonUser["notes"] = notes;

            userList.push_back(jsonUser);
        }

        return userList;
    }
};

#endif //DTO_ASSEMBLER_HPP
