#ifndef ORDER_REPOSITORY_HPP
#define ORDER_REPOSITORY_HPP

#include <pqxx/pqxx>
#include "factory.hpp"
#include "order.hpp"

using namespace std;

namespace Repository {
    inline void addOrder(const Order& order, pqxx::work& W) {
        W.exec_params("INSERT orders (user_id, product_id, shopping_date) VALUES ($1, $2, $3)",
            order.userId, order.productId, order.shoppingDate);
    }

    inline void deleteOrder(int id, pqxx::work& W) {
        W.exec_params("DELETE FROM orders WHERE id = $1", id);
        W.commit();
    }

    inline vector<Order> listOrders(pqxx::connection& dbConnection) {
        pqxx::nontransaction N(dbConnection);
        const pqxx::result result = N.exec("SELECT "
                                           "o.id AS order_id,"
                                           " u.id AS user_id, "
                                           "p.id AS product_id,"
                                           "u.name AS user_name,"
                                           "u.surname AS user_surname,"
                                           "u.phone_number AS user_phone,"
                                           "u.email AS user_email,"
                                           "u.address AS user_address,"
                                           "p.name AS product_name,"
                                           "p.price AS product_price,"
                                           "p.quantity AS product_quantity,"
                                           "o.shopping_date"
                                           "FROM orders o"
                                           " INNER JOIN users u ON o.user_id = u.id"
                                           " INNER JOIN products p ON o.product_id = p.id");
        return Factory::createOrderFromResult(result);
    }
}

#endif