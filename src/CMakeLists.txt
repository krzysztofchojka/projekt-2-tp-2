# src/CMakeLists.txt

# Tworzenie biblioteki statycznej z Graph.cpp
add_library(GraphLib Graph.cpp)

# Ustawienie katalogu z nagłówkami
target_include_directories(GraphLib PUBLIC ../include)

# Tworzenie głównego wykonywalnego pliku
add_executable(main_exe main.cpp)

# Linkowanie biblioteki z wykonywalnym plikiem
target_link_libraries(main_exe PRIVATE GraphLib)


add_library(cmpVectorsFunc compareVectors.cpp)
target_include_directories(cmpVectorsFunc PUBLIC ../include)