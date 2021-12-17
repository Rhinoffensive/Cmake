cmake_minimum_required(VERSION 3.13)
project(Demo)




set(CMAKE_CXX_STANDARD 17)



add_executable(${PROJECT_NAME} main.cpp )


add_subdirectory(Adder)

add_subdirectory(glfw)
#target_include_directories(${PROJECT_NAME} PUB)

target_include_directories(${PROJECT_NAME}
        PUBLIC Adder
        PUBLIC glfw/include)

target_link_directories(${PROJECT_NAME}
        PRIVATE Adder
        PRIVATE glfw/src)

target_link_libraries(${PROJECT_NAME} adder glfw)