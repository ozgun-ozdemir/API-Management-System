#ifndef BASKET_REPOSITORY_HPP
#define BASKET_REPOSITORY_HPP

#include <pqxx/pqxx>
#include "basket.hpp"
#include "factory.hpp"

using namespace std;

namespace Repository {
    inline void addBasket(const Basket& basket, pqxx::work& W) {
        W.exec_params("INSERT INTO baskets (user_id, product_id, shopping_date) VALUES ($1, $2, $3)",
            basket.userId, basket.productId, basket.shoppingDate);
    }

    inline void deleteBasket(int id, pqxx::work& W) {
        W.exec_params("DELETE FROM baskets WHERE id = $1", id);
        W.commit();
    }

    inline vector<Basket> listBaskets(pqxx::connection& dbConnection) {
        pqxx::nontransaction N(dbConnection);
        const pqxx::result result = N.exec("SELECT id, user_id, product_id, shopping_date FROM baskets");
        return Factory::createFromResult(result);
    }
}

#endif