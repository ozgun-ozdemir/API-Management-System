# Simple REST API with Crow and PostgreSQL
This project implements a simple RESTful API using the Crow microframework and PostgreSQL for database management. The API provides endpoints for managing users, products, and orders.

## Features
- **User Management**: Add, update, delete, and list users.
- **Product Management**: Add, update, delete, and list products.
- **Order Management**: Create and delete orders, and retrieve order details.

## Requirements
- C++11 or higher
- Crow library
- libpqxx
- PostgreSQL database

## Installation
**SQL queries to create the users, products, and orders table for PostgreSQL**:
1. Users Table
   CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    surname VARCHAR(100) NOT NULL,
    phone_number VARCHAR(15),
    email VARCHAR(100) UNIQUE NOT NULL,
    address TEXT
);asa]
2. Products Table
CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    price DECIMAL(10, 2) NOT NULL,
    quantity INT NOT NULL CHECK (quantity >= 0)

);
3. Orders Table
CREATE TABLE orders (
    id SERIAL PRIMARY KEY,
    user_id INT REFERENCES users(id) ON DELETE CASCADE,
    product_id INT REFERENCES products(id) ON DELETE CASCADE,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
