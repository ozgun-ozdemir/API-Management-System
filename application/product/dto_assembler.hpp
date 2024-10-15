#ifndef DTO_ASSEMBLER2_HPP
#define DTO_ASSEMBLER2_HPP

#include <crow/json.h>
#include <vector>
#include "product/product.hpp"

namespace DtoAssembler {

    inline crow::json::wvalue toJson(const vector<Product>& products) {
        crow::json::wvalue::list productList;
        crow::json::wvalue jsonProduct;

        for (const auto& [id, name, price, quantity] : products) {
            jsonProduct["id"] = id;
            jsonProduct["name"] = name;
            jsonProduct["price"] = price;
            jsonProduct["quantity"] = quantity;


            productList.push_back(jsonProduct);
        }

        return productList;
    }
};

#endif //DTO_ASSEMBLER2_HPP
