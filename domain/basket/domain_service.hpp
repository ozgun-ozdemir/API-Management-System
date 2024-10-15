#ifndef BASKET_DOMAIN_SERVICE_HPP
#define BASKET_DOMAIN_SERVICE_HPP

#include "repository.hpp"
#include "basket.hpp"

using namespace std;

namespace DomainService {
    inline void addBasket(const int userId, const int productId, const string& shoppingDate, pqxx::work& W) {
        const Basket basket{userId, productId, shoppingDate};
        Repository::addBasket(basket, W);
    }

    inline void deleteBasket(const int id, pqxx::work& W) {
        Repository::deleteBasket(id, W);
    }

    inline vector<Basket> listBaskets(pqxx::connection& dbConnection) {
        return Repository::listBaskets(dbConnection);
    };

}

#endif