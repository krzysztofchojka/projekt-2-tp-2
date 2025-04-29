cmake_minimum_required(VERSION 3.10)
project(DFSAssignment)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodanie podkatalogów
add_subdirectory(src)
add_subdirectory(tests)

# Utf-8 na Windows aby działały polskie znaki w cmd
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# Enable testing
enable_testing()