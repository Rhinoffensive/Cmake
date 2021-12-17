cmake_minimum_required(VERSION 3.13)
project(Demo)




set(CMAKE_CXX_STANDARD 17)



add_executable(${PROJECT_NAME} main.cpp )
add_subdirectory(Adder)
target_link_libraries(${PROJECT_NAME} adder)