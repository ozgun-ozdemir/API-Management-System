#ifndef USER_HPP
#define USER_HPP

#include <string>

using namespace std;

class User {
public:
    int id{};
    string name;
    string surname;
    string phoneNumber;
    string email;
    string notes;

    User() = default;

    User(string name, string surname, string phone, string email, string notes)
        : name(std::move(name)), surname(std::move(surname)), phoneNumber(std::move(phone)), email(std::move(email)), notes(std::move(notes)) {}
};

#endif
