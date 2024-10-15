cmake_minimum_required(VERSION 3.29)
project(DDD)

set(CMAKE_CXX_STANDARD 20)

find_package(Crow CONFIG REQUIRED)
find_package(libpqxx REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/application
        ${CMAKE_SOURCE_DIR}/domain)

add_executable(DDD main.cpp
        domain/user/user.hpp
        domain/user/factory.hpp
        domain/user/repository.hpp
        domain/user/domain_service.hpp
        application/user/application_service.hpp
        application/user/dto_assembler.hpp
        infrastructure/infrastructure.hpp
        application/product/dto_assembler.hpp
        application/product/application_service.hpp
        domain/product/domain_service.hpp
        domain/product/product.hpp
        domain/product/repository.hpp
        domain/product/factory.hpp
        application/basket/application_service.hpp
        domain/basket/basket.hpp
        domain/basket/domain_service.hpp
        domain/basket/repository.hpp
        domain/basket/domain_service.hpp
        domain/basket/factory.hpp
        application/basket/dto_assembler.hpp


)

target_link_libraries(DDD PRIVATE
        Crow::Crow
        libpqxx::pqxx)
