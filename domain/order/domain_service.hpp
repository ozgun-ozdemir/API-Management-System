#ifndef ORDER_DOMAIN_SERVICE_HPP
#define ORDER_DOMAIN_SERVICE_HPP

#include "repository.hpp"
#include "order.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

namespace DomainService {
    inline string getCurrentDateTime() {
        const time_t now = time(nullptr);
        const tm* localTime = localtime(&now);
        ostringstream dateStream;
        dateStream << put_time(localTime, "%Y-%m-%d %H:%M:%S");
        return dateStream.str();
    }

    inline void addOrder(const int userId, const int productId, pqxx::work& W) {
        const string shoppingDate = getCurrentDateTime();
        const Order order{userId, productId, shoppingDate};
        Repository::addOrder(order, W);
    }

    inline void deleteOrder(const int id, pqxx::work& W) {
        Repository::deleteOrder(id, W);
    }

    inline vector<Order> listOrders(pqxx::connection& dbConnection) {
        return Repository::listOrders(dbConnection);
    }
}

#endif