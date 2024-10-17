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
    string address;

    User() = default;

    User(string name, string surname, string phone, string email, string address)
        : name(std::move(name)), surname(std::move(surname)), phoneNumber(std::move(phone)), email(std::move(email)), address(std::move(address)) {}
};

#endif
