cmake_minimum_required(VERSION 4.1)
project(Password_Manager_FP)

set(CMAKE_CXX_STANDARD 20)

find_package(unofficial-argon2 CONFIG REQUIRED)

add_executable(Password_Manager_FP main.cpp)
target_link_libraries(Password_Manager_FP PRIVATE unofficial::argon2::libargon2)
