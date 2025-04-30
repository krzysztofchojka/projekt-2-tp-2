# Techniki Programowania - Projekt 2

>*Krzysztof&nbsp;Chojka&nbsp;203183, Daniel&nbsp;Chrzanowski&nbsp;203381* **ACIR&nbsp;1B**


1. [Opis Projektu / Zadanie](#zadanie-3)
2. [Kompilowanie](#kompilowanie)
3. [Skrypty Automatyzujące](#skrypty-automatyzujące)
4. [Struktura Projektu](#struktura-projektu)
5. [Opis Klas i Funkcji](#opis-klas-i-funkcji)


### Zadanie 3

Napisz program przeszukujący graf w głąb metodą DFS. Jako strukturę sterującą kolejnością przeszukiwania wierzchołków wykorzystaj stos (`stack`) z biblioteki STL. Graf reprezentuj jako wektor STL (`vector`), którego każdy element jest wektorem sąsiadów odpowiedniego wierzchołka.



### Dodatkowe wymagania

- Przeszukiwanie grafu należy wykonywać w osobnym wątku tuż po otrzymaniu grafu.
- Program powinien wczytać co najmniej dwa różne grafy i uruchomić osobny wątek dla każdego (z użyciem `std::thread` i przekazania przez referencję `std::ref`).
- Dodatkowo wykorzystać `std::packaged_task`.
<br><br>
---
### Kompilowanie
Utwórz i przejdź do katalogu `build`.
```
mkdir build && cd build
```
Konfiguracja projektu z CMake.
```
cmake ..
```

Skompiluj projekt.
```
cmake --build .
```
Uruchamianie testów (w katalogu `build`).
```
ctest
```
### Skrypty automatyzujące

Projekt posiada skrypty upraszczające prace.

`scripts_linux.sh` - dla systemu Linux

`scripts_macos.command` - dla systemu MacOS

`scripts_windows.bat` - dla systemu Windows

Po ich uruchomienu ukaże się menu pozwalające automatycznie skompilować projekt, uruchomić program lub testy.

```
user@MacBook-Air-Krzysztof projekt-2-tp-2 % ./scripts_macos.command 
---------------------------------
 Scripts 
---------------------------------
c - Recompile project
r - Run main executable
t - Run tests via ctest
q - Quit
---------------------------------
Enter your choice (r/t/c/q):
```

---

### Struktura Projektu

Projekt składa się z następujących plików:

- `include/Graph.h`: Deklaracja klasy Graph oraz jej publicznych i prywatnych metod.
- `include/compareVectors.h`: Deklaracja funkcji compareVectors wykorzystywanej przy testach.
- `src/Graph.cpp`: Implementacja metod klasy Graph.
- `src/compareVectors.cpp`: Implementacja funkcji compareVectors.
- `src/main.cpp`: Funkcja główna programu, wczytująca grafy i uruchamiająca przeszukiwanie DFS w osobnych wątkach.
- `tests/*.cpp`: 10 różnych testów, każy z innym roadzej grafu.
- `tests/test_main.cpp`: pierwsza wersja testów, nie używane

---

### Opis Klas i Funkcji

#### Plik `Graph.h`


- **Graph**: Klasa reprezentująca graf jako lista sąsiedztwa.
    - **Graph(int vertices)**: Konstruktor inicjalizujący graf z określoną liczbą wierzchołków.
    - **void addEdge(int src, int dest)**: Metoda dodająca krawędź od `src` do `dest`. Sprawdza poprawność indeksów wierzchołków.
    - **void DFS(int start)**: Metoda wykonująca przeszukiwanie DFS od wierzchołka `start`. Wynik jest wypisywany na standardowe wyjście.
    - **void printDFS(const std::vector<int> &traversal)**: Metoda pomocnicza do wypisywania kolejności odwiedzin wierzchołków.
    - **std::future<std::vector<int>> runDFSAsync(int start)**: Metoda uruchamiająca przeszukiwanie DFS w osobnym wątku i zwracająca `std::future` z wynikiem przeszukiwania.
    - **void printGraph()**: Metoda wypisująca liste sąsiedztwa grafu.

#### Plik `Graph.cpp`


- **Graph(int vertices)**: Inicjalizuje graf z `vertices` wierzchołkami, tworząc pustą listę sąsiedztwa dla każdego wierzchołka.
- **void addEdge(int src, int dest)**: Dodaje krawędź od `src` do `dest`, jeśli indeksy wierzchołków są poprawne.
- **void DFS(int start)**: Implementuje algorytm DFS używając stosu (`std::stack`). Używa tablicy `visited` do śledzenia odwiedzonych wierzchołków oraz wektora `traversal` do przechowywania kolejności odwiedzin. Po zakończeniu przeszukiwania wypisuje wynik przy pomocy `printDFS`.
- **void printDFS(const std::vector<int> &traversal)**: Iteruje przez wektor `traversal` i wypisuje kolejność odwiedzonych wierzchołków.
- **std::future<std::vector<int>> runDFSAsync(int start)**:
    - Tworzy `std::packaged_task`, który zawiera lambdę implementującą algorytm DFS.
    - Pobiera `future` z `packaged_task` do późniejszego pobrania wyniku.
    - Uruchamia `packaged_task` w osobnym wątku, który jest odłączony (`detach`).
    - Zwraca `future`, który umożliwia odbiór wyniku przeszukiwania.
- **void printGraph()**: Wyświetla listę sąsiedztwa grafu, iterując przez wszystkie wierzchołki i wyświetlając ich sąsiadów.

#### Plik `main.cpp`

- Wczytuje wierzchołki i krawędzie dla dwóch grafów of użytkownika.
- Uruchamia dla każdego grafu asynchroniczne przeszukiwanie DFS przy użyciu `runDFSAsync`.
- Odbiera i wypisuje wyniki po zakończeniu wątków.

Plik `compareVectors.cpp`
- **bool compareVectors(const std::vector<int>& a, const std::vector<int>& b)**: Przyjmuje dwa wektory a oraz b i porównuje je.
- Sprawdza, czy długości wektorów są takie same. Jeśli nie, zwraca false.
- Iteruje przez oba wektory i porównuje elementy o tych samych indeksach. Jeśli napotka różnice, zwraca false.
- Jeśli wszystkie elementy są identyczne, zwraca true.
