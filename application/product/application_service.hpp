#ifndef APPLICATION_SERVER2_HPP
#define APPLICATION_SERVER2_HPP

#include "../domain/product/domain_service.hpp"
#include "product/dto_assembler.hpp"

using namespace std;

namespace ApplicationServer {
    inline void addProduct(pqxx::work& W, const string& name, const string& price, const string& quantity) {
        DomainService::addProduct(name, price, quantity, W);
    }

    inline void updateProduct(pqxx::work& W, const int id, const string& name, const string& price, const string& quantity) {
        DomainService::updateProduct(id, name, price, quantity, W);
    }

    inline void deleteProduct(const int id, pqxx::work& W) {
        DomainService::deleteProduct(id, W);
    }

    inline crow::json::wvalue listProducts(pqxx::connection& dbConnection) {
        const vector<Product> products = DomainService::listProducts(dbConnection);
        return DtoAssembler::toJson(products);
    }
}

#endif
