cmake_minimum_required(VERSION 3.23)
project(STL)

set(CMAKE_CXX_STANDARD 14)

add_executable(vector vector_test.cpp )
add_executable(string string_tset.cpp)
add_executable(template template_test.cpp)
