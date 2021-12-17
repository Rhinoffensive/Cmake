cmake_minimum_required(VERSION 3.13)
project(Demo VERSION 2.3)

configure_file(DemoConfig.h.in DemoConfig.h)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp )
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
message(STATUS ${PROJECT_NAME}  " created!" ${PROJECT_BINARY_DIR})


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