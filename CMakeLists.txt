cmake_minimum_required(VERSION 3.29)
project(DDD)

set(CMAKE_CXX_STANDARD 20)

find_package(Crow CONFIG REQUIRED)
find_package(libpqxx REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/application
        ${CMAKE_SOURCE_DIR}/domain)

add_executable(DDD main.cpp
        domain/contact/contact.hpp
        domain/contact/factory.hpp
        domain/contact/repository.hpp
        domain/contact/domain_service.hpp
        application/application_service.hpp
        application/dto-assembler.hpp
        infrastructure/infrastructure.hpp
)

target_link_libraries(DDD PRIVATE
        Crow::Crow
        libpqxx::pqxx)
