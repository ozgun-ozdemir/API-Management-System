#ifndef ORDER_APPLICATION_HPP
#define ORDER_APPLICATION_HPP

#include "../domain/order/domain_service.hpp"
#include "../order/dto_assembler.hpp"

using namespace std;

namespace ApplicationServer {
    inline void addOrder(pqxx::work& W, const int userId, const int productId) {
        DomainService::addOrder(userId, productId, W);
    }

    inline void deleteOrder(const int id, pqxx::work & work) {
        DomainService::deleteOrder(id, work);
    }

    inline crow::json::wvalue listOrders(pqxx::connection& dbConnection) {
        const vector<Order> orders = DomainService::listOrders(dbConnection);
        return DtoAssembler::toJson(orders);
    }

    inline crow::json::wvalue getOrderById(const int id, pqxx::connection& dbConnection) {
        const Order order = DomainService::getOrderById(id, dbConnection);
        return DtoAssembler::toJson({order});
    }
}

#endif // ORDER_APPLICATION_HPP