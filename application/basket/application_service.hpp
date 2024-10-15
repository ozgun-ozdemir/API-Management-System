#ifndef BASKET_APPLICATION_HPP
#define BASKET_APPLICATION_HPP

#include "../domain/basket/domain_service.hpp"
#include "basket/dto_assembler.hpp"

using namespace std;

namespace ApplicationServer {
    inline void addBasket(pqxx::work& W, const int userId, const int productId, const string& shoppingDate) {
        DomainService::addBasket(userId, productId, shoppingDate, W);
    }

    inline void deleteBasket(const int id, pqxx::work & work) {
        DomainService::deleteBasket(id, work);
    }
    inline crow::json::wvalue listBaskets(pqxx::connection& dbConnection) {
        const vector<Basket> baskets = DomainService::listBaskets(dbConnection);
        return DtoAssembler::toJson(baskets);
    }

}

#endif // BASKET_APPLICATION_HPP
