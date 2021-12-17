cmake_minimum_required(VERSION 3.13)
project(Demo VERSION 2.3)



# adder use logic

option(USE_ADDER "A simple library for adding 2 floats." OFF)

if(USE_ADDER)
    add_subdirectory(Adder)

    list(APPEND EXTRA_LIBS "Adder")
    list(APPEND EXTRA_INCLUDES "Adder")
    list(APPEND EXTRA_LINKS adder)

endif()

configure_file(DemoConfig.h.in DemoConfig.h)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp )

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

message(STATUS ${PROJECT_NAME}  " created! " ${PROJECT_BINARY_DIR})




add_subdirectory(glfw)
#target_include_directories(${PROJECT_NAME} PUB)

target_include_directories(${PROJECT_NAME}
        PUBLIC glfw/include
        ${EXTRA_INCLUDES})

target_link_directories(${PROJECT_NAME}
        PRIVATE glfw/src
        ${EXTRA_LIBS})

target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} glfw)