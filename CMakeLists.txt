cmake_minimum_required(VERSION 3.10)  # Minimum required CMake version
project(MyProject)  # Project name

set(CMAKE_CXX_STANDARD 17)  # Set C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ex8 test.cpp)  # Create an executable from test.cpp


enable_testing()
add_test(NAME queue_test COMMAND test_queue)