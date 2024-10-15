#ifndef DOMAIN_SERVICE2_HPP
#define DOMAIN_SERVICE2_HPP

#include "repository.hpp"
#include "product.hpp"

using namespace std;

namespace DomainService {
    inline void addProduct(const string& name, const string& price, const string& quantity, pqxx::work& W) {
        const Product product{name, price, quantity};
        Repository::addProduct(product, W);
    }

    inline void updateProduct(const int id, const string& name, const string& price, const string& quantity, pqxx::work& W) {
        Product product{name, price, quantity};
        product.id = id;
        Repository::updateProduct(product, W);
    }

    inline void deleteProduct(const int id, pqxx::work& W) {
        Repository::deleteProduct(id, W);
    }

    inline vector<Product> listProducts(pqxx::connection& dbConnection) {
        return Repository::listProducts(dbConnection);
    }
}

#endif
