cmake_minimum_required(VERSION 3.12.0)
set (CMAKE_CXX_STANDARD 14)
project (DataStructures)

# Headers
include_directories(include)

# Sources
set(SOURCES include/SinglyLinkedList.hpp src/SinglyLinkedList.cpp include/Stack.hpp src/Stack.cpp src/main.cpp)


add_executable(DataStructures ${SOURCES})
