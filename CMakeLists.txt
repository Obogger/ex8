cmake_minimum_required(VERSION 3.22)  # Minimum required CMake version
project(MyProject)  # Project name

enable_testing()


set(CMAKE_CXX_STANDARD 17)  # Set C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test_queue test.cpp)  # Create an executable from test.cpp


add_test(NAME queue_test COMMAND test_queue)

