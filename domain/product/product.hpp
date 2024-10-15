#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
public:
    int id{};
    string name;
    string price;
    string quantity;

    Product() = default;

    Product(string name, string price, string quantity)
        : name(std::move(name)), price(std::move(price)), quantity(std::move(quantity)) {}
};

#endif
