cmake_minimum_required(VERSION 3.10)
project(DFSAssignment)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodanie podkatalogów
add_subdirectory(src)
add_subdirectory(tests)