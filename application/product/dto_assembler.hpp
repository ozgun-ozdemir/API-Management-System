#ifndef DTO_ASSEMBLER2_HPP
#define DTO_ASSEMBLER2_HPP


namespace DtoAssembler {

    inline crow::json::wvalue toJson(const vector<Product>& products) {
        crow::json::wvalue::list jsonProductList;

        for (const auto& [id, name, price, quantity] : products) {
            crow::json::wvalue jsonProduct;
            jsonProduct["id"] = id;
            jsonProduct["name"] = name;
            jsonProduct["price"] = price;
            jsonProduct["quantity"] = quantity;

            jsonProductList.push_back(jsonProduct);
        }

        return jsonProductList;
    }
};

#endif //DTO_ASSEMBLER2_HPP
