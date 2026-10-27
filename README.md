# AiSD_Lekcja3
## AiSD (3) - ADT LIST (implementacja tablicowa)
### Tablica statyczna w C++

Projekt zawiera implementację struktury danych ADT LIST w oparciu o tablicę o stałym rozmiarze (tablica statyczna). 

Implementacja została zrealizowana jako szablon klasy `ArrayList`. Poprawność działania wszystkich wymaganych i opcjonalnych metod (w tym konstruktorów kopiujących i przenoszących) jest weryfikowana w pliku `main.cpp` za pomocą testów automatycznych z użyciem funkcji `assert()`.

### Zawartość
- `arraylist.hpp` - szablon klasy ArrayList z pełną implementacją metod.
- `main.cpp` - program testujący działanie struktury i jej interfejsu.
- `Makefile` - skrypt ułatwiający kompilację.

### Jak uruchomić?
Wymagany jest system z zainstalowanym kompilatorem g++ oraz programem make. W terminalu wpisać jedną z poniższych komend:
- `make run` – kompiluje program i od razu go uruchamia.
- `make` – tylko kompiluje program (tworzy plik main.out).
- `make clean` – usuwa pliki binarne i obiektowe wygenerowane podczas kompilacji.
