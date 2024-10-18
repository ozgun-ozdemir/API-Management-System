#ifndef ORDER_FACTORY_HPP
#define ORDER_FACTORY_HPP

#include "order.hpp"
#include <pqxx/pqxx>
#include <crow.h>

using namespace std;

namespace Factory {
    inline vector<Order> createOrderFromResult(const pqxx::result& result) {
        vector<Order> orderList;

        for (const auto& row : result) {
            Order order;
            order.id = row["order_id"].as<int>();
            order.userId = row["user_id"].as<int>();
            order.productId = row["product_id"].as<int>();
            order.shoppingDate = row["shopping_date"].as<string>();
            order.userName = row["user_name"].as<string>();
            order.userSurname = row["user_surname"].as<string>();
            order.userPhone = row["user_phone"].as<string>();
            order.userEmail = row["user_email"].as<string>();
            order.userAddress = row["user_address"].as<string>();
            order.productName = row["product_name"].as<string>();
            order.productPrice = row["product_price"].as<string>();
            order.productQuantity = row["product_quantity"].as<string>();

            orderList.push_back(order);
        }

        return orderList;
    }
}

#endif