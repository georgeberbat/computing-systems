cmake_minimum_required(VERSION 3.23)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c cmake-build-debug/node.c DoublyLinkedList.c DoublyLinkedList.h Stack.h Stack.c)
