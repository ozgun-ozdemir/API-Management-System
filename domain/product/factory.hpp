#ifndef FACTORY2_HPP
#define FACTORY2_HPP

#include "product.hpp"
#include <pqxx/pqxx>
#include <crow.h>

using namespace std;

namespace Factory {
    inline Product create(const string& name, const string& price, const string& quantity) {
        return Product{name, price, quantity};
    }

    inline vector<Product> createProductFromResult(const pqxx::result& result) {
        vector<Product> productList;

        for (const auto& row : result) {
            Product product;
            product.id = row[0].as<int>();
            product.name = row[1].as<string>();
            product.price = row[2].as<string>();
            product.quantity = row[3].as<string>();

            productList.push_back(product);
        }

        return productList;
    }
}

#endif
