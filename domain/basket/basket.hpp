#ifndef BASKET_HPP
#define BASKET_HPP

#include <string>

using namespace std;

class Basket {
public:
    int id{};
    int userId{};
    int productId{};
    string shoppingDate;

    Basket() = default;

    Basket(const int userId, const int productId, string shoppingDate)
        : userId(userId), productId(productId), shoppingDate(std::move(shoppingDate)) {}
};

#endif