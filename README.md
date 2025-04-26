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