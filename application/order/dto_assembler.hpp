#ifndef ORDER_DTO_ASSEMBLER_HPP
#define ORDER_DTO_ASSEMBLER_HPP

using namespace std;

namespace DtoAssembler {

    inline crow::json::wvalue toJson(const vector<Order>& orders) {
        crow::json::wvalue::list jsonOrderList;


        for (const auto& order : orders) {
            crow::json::wvalue jsonOrder;
            jsonOrder["id"] = order.id;
            jsonOrder["user_id"] = order.userId;
            jsonOrder["product_id"] = order.productId;
            jsonOrder["shopping_date"] = order.shoppingDate;
            jsonOrder["user_name"] = order.userName;
            jsonOrder["user_surname"] = order.userSurname;
            jsonOrder["user_phone"] =  order.userPhone;
            jsonOrder["user_email"] = order.userEmail;
            jsonOrder["user_address"] = order.userAddress;
            jsonOrder["product_name"] = order.productName;
            jsonOrder["product_price"] = order.productPrice;
            jsonOrder["product_quantity"] = order.productQuantity;

            jsonOrderList.push_back(jsonOrder);
        }

        return jsonOrderList;
    }

}

#endif