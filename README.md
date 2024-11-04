# API Management System
This project implements a simple RESTful API using the Crow micro framework and PostgreSQL for database management. The API provides endpoints for managing users, products, and orders.

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
**Create the database and table: CREATE DATABASE your_database_name;**:
-  Users Table -
   CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    surname VARCHAR(50) NOT NULL,
    phone_number VARCHAR(20),
    email VARCHAR(50) UNIQUE NOT NULL,
    address TEXT);

- Products Table -
CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    price int NOT NULL,
    quantity INT NOT NULL CHECK);

- Orders Table -
CREATE TABLE orders (
    id SERIAL PRIMARY KEY,
    user_id INT REFERENCES users(id) ON DELETE CASCADE,
    product_id INT REFERENCES products(id) ON DELETE CASCADE,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP);
