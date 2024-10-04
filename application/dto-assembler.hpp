#ifndef DTO_ASSEMBLER_HPP
#define DTO_ASSEMBLER_HPP

#include <crow/json.h>
#include <vector>
#include "contact/contact.hpp"

namespace DtoAssembler {

    inline crow::json::wvalue toJson(const vector<Contact>& contacts) {
        crow::json::wvalue::list contactList;
        crow::json::wvalue jsonContact;

        for (const auto&[id, name, surname, phone_number, email, notes] : contacts) {
            jsonContact["id"] = id;
            jsonContact["name"] = name;
            jsonContact["surname"] = surname;
            jsonContact["phone_number"] = phone_number;
            jsonContact["email"] = email;
            jsonContact["notes"] = notes;

            contactList.push_back(jsonContact);
        }

        return contactList;
    }
};

#endif //DTO_ASSEMBLER_HPP