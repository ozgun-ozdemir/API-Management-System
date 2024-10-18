#ifndef DTO_ASSEMBLER_HPP
#define DTO_ASSEMBLER_HPP

namespace DtoAssembler {

    inline crow::json::wvalue toJson(const vector<User>& users) {
        crow::json::wvalue::list jsonUserList;


        for (const auto& [id, name, surname, phoneNumber, email, address] : users) {
            crow::json::wvalue jsonUser;
            jsonUser["id"] = id;
            jsonUser["name"] = name;
            jsonUser["surname"] = surname;
            jsonUser["phone_number"] = phoneNumber;
            jsonUser["email"] = email;
            jsonUser["address"] = address;

            jsonUserList.push_back(jsonUser);
        }

        return jsonUserList;
    }
};

#endif //DTO_ASSEMBLER_HPP
