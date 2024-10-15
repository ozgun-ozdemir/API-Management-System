#ifndef BASKET_DTO_ASSEMBLER_HPP
#define BASKET_DTO_ASSEMBLER_HPP

#include <crow/json.h>
#include <vector>
#include "basket/basket.hpp"

using namespace std;

namespace DtoAssembler {

    inline crow::json::wvalue toJson(const vector<Basket>& baskets) {
        crow::json::wvalue::list basketList;
        crow::json::wvalue jsonBasket;

        for (const auto& basket : baskets) {
            jsonBasket["id"] = basket.id;
            jsonBasket["user_id"] = basket.userId;
            jsonBasket["product_id"] = basket.productId;
            jsonBasket["shopping_date"] = basket.shoppingDate;

            basketList.push_back(jsonBasket);
        }

        return basketList;
    }
}

#endif