#ifndef REPOSITORY2_HPP
#define REPOSITORY2_HPP


#include "product.hpp"
#include "factory.hpp"
#include <pqxx/pqxx>


using namespace std;

namespace Repository {
    inline void addProduct(const Product& product, pqxx::work& W) {
        W.exec_params("INSERT INTO products (name, price, quantity) VALUES ($1, $2, $3)",
            product.name, product.price, product.quantity);
    }

    inline void updateProduct(const Product& product, pqxx::work& W) {
        W.exec_params("UPDATE products SET name = $1, price = $2, quantity = $3 WHERE id = $4",
            product.name, product.price, product.quantity, product.id);
    }

    inline void deleteProduct(const int id, pqxx::work& W) {
        W.exec_params("DELETE FROM products WHERE id = $1", to_string(id));
    }

    inline vector<Product> listProducts(pqxx::connection& db_connection) {
        pqxx::nontransaction N(db_connection);
        const pqxx::result result = N.exec("SELECT id, name, price, quantity FROM products");
        return Factory::createProductFromResult(result);
    }
}

#endif
