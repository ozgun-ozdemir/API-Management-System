#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>

using namespace std;

class Order {
public:
    int id{};
    int userId{};
    int productId{};
    string shoppingDate;
    string userName;
    string userSurname;
   string userPhone;
   string userEmail;
   string userAddress;
    string productName;
    string productPrice;
    string productQuantity;

    Order() = default;

    Order(const int userId, const int productId, string shoppingDate)
        : userId(userId), productId(productId), shoppingDate(std::move(shoppingDate)) {}
};


#endif
