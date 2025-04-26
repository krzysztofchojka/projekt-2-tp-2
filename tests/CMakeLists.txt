# tests/CMakeLists.txt

add_executable(tests test_main.cpp)

# Ustawienie katalogu z nagłówkami
target_include_directories(tests PRIVATE ../include)

# Linkowanie z biblioteką GraphLib
target_link_libraries(tests PRIVATE GraphLib)