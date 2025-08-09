cmake_minimum_required(VERSION 4.0)

project(noteman VERSION 0.1 LANGUAGES CXX)

# C++ Standards
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SRC_FILESOUT 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

message(STATUS "Sources : ${SRC_FILESOUT}")

add_executable(noteman ${SRC_FILESOUT})

target_include_directories(noteman PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
