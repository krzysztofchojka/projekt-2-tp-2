# Techniki Programowania - Projekt 2

>*Krzysztof&nbsp;Chojka&nbsp;203183, Daniel&nbsp;Chrzanowski&nbsp;203381* **ACIR&nbsp;1B**


### Zadanie 3

Napisz program przeszukujący graf w głąb metodą DFS. Jako strukturę sterującą kolejnością przeszukiwania wierzchołków wykorzystaj stos (`stack`) z biblioteki STL. Graf reprezentuj jako wektor STL (`vector`), którego każdy element jest wektorem sąsiadów odpowiedniego wierzchołka.



### Dodatkowe wymagania

- Przeszukiwanie grafu należy wykonywać w osobnym wątku tuż po otrzymaniu grafu.
- Program powinien wczytać co najmniej dwa różne grafy i uruchomić osobny wątek dla każdego (z użyciem `std::thread` i przekazania przez referencję `std::ref`).
- Dodatkowo wykorzystać `std::packaged_task`.
<br><br>
---


### Struktura Projektu

Projekt składa się z następujących plików:

- **include/Graph.h**: Deklaracja klasy Graph oraz jej publicznych i prywatnych metod.
- **src/Graph.cpp**: Implementacja metod klasy Graph.
- **src/main.cpp**: Funkcja główna programu, tworząca grafy i uruchamiająca przeszukiwanie DFS w osobnych wątkach.

---

### Opis Klas i Funkcji

#### Plik Graph.h



- **Graph**: Klasa reprezentująca graf jako lista sąsiedztwa.
    - **Graph(int vertices)**: Konstruktor inicjalizujący graf z określoną liczbą wierzchołków.
    - **void addEdge(int src, int dest)**: Metoda dodająca krawędź od `src` do `dest`. Sprawdza poprawność indeksów wierzchołków.
    - **void DFS(int start)**: Metoda wykonująca przeszukiwanie DFS od wierzchołka `start`. Wynik jest wypisywany na standardowe wyjście.
    - **void printDFS(const std::vector<int> &traversal)**: Metoda pomocnicza do wypisywania kolejności odwiedzin wierzchołków.
    - **std::future<std::vector<int>> runDFSAsync(int start)**: Metoda uruchamiająca przeszukiwanie DFS w osobnym wątku i zwracająca `std::future` z wynikiem przeszukiwania.

#### Plik Graph.cpp


- **Graph(int vertices)**: Inicjalizuje graf z `vertices` wierzchołkami, tworząc pustą listę sąsiedztwa dla każdego wierzchołka.
- **void addEdge(int src, int dest)**: Dodaje krawędź od `src` do `dest`, jeśli indeksy wierzchołków są poprawne.
- **void DFS(int start)**: Implementuje algorytm DFS używając stosu (`std::stack`). Używa tablicy `visited` do śledzenia odwiedzonych wierzchołków oraz wektora `traversal` do przechowywania kolejności odwiedzin. Po zakończeniu przeszukiwania wypisuje wynik przy pomocy `printDFS`.
- **void printDFS(const std::vector<int> &traversal)**: Iteruje przez wektor `traversal` i wypisuje kolejność odwiedzonych wierzchołków.
- **std::future<std::vector<int>> runDFSAsync(int start)**:
    - Tworzy `std::packaged_task`, który zawiera lambdę implementującą algorytm DFS.
    - Pobiera `future` z `packaged_task` do późniejszego pobrania wyniku.
    - Uruchamia `packaged_task` w osobnym wątku, który jest odłączony (`detach`).
    - Zwraca `future`, który umożliwia odbiór wyniku przeszukiwania.

#### Plik main.cpp

- Tworzy kilka instancji grafów.
- Dodaje krawędzie do grafów.
- Uruchamia dla każdego grafu asynchroniczne przeszukiwanie DFS przy użyciu `runDFSAsync`.
- Odbiera i wypisuje wyniki po zakończeniu wątków.

