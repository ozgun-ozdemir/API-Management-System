#ifndef BASKET_FACTORY_HPP
#define BASKET_FACTORY_HPP

#include "basket.hpp"
#include <pqxx/pqxx>
#include <vector>

using namespace std;

namespace Factory {
    inline Basket create(const int userId, const int productId, const string& shoppingDate) {
        return Basket{userId, productId, shoppingDate};
    }

    inline vector<Basket> createFromResult(const pqxx::result& result) {
        vector<Basket> basketList;

        for (const auto& row : result) {
            Basket basket;
            basket.id = row[0].as<int>();
            basket.userId = row[1].as<int>();
            basket.productId = row[2].as<int>();
            basket.shoppingDate = row[3].as<std::string>();

            basketList.push_back(basket);
        }

        return basketList;
    }
}

#endif