cmake_minimum_required(VERSION 3.29)
project(DDD)

set(CMAKE_CXX_STANDARD 20)

find_package(Crow CONFIG REQUIRED)
find_package(libpqxx REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/application
        ${CMAKE_SOURCE_DIR}/domain)

add_executable(DDD main.cpp
        infrastructure/infrastructure.hpp
        application/user/application_service.hpp
        application/user/dto_assembler.hpp
        domain/user/user.hpp
        domain/user/domain_service.hpp
        domain/user/factory.hpp
        domain/user/repository.hpp
        application/product/application_service.hpp
        application/product/dto_assembler.hpp
        domain/product/domain_service.hpp
        domain/product/product.hpp
        domain/product/repository.hpp
        domain/product/factory.hpp
        application/order/application_service.hpp
        application/order/dto_assembler.hpp
        domain/order/order.hpp
        domain/order/domain_service.hpp
        domain/order/repository.hpp
        domain/order/factory.hpp


)

target_link_libraries(DDD PRIVATE
        Crow::Crow
        libpqxx::pqxx)
