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


#           DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#           CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

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