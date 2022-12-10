# Projekt zaliczeniowy : AiSD I
### Temat projekt:

Implementacja wielomianów na bazie tablic (szablon, współczynniki typu T). Działania na wielomianach: dodawanie (operator+), odejmowanie (operator-), mnożenie (operator*), sprzężenie, porównywanie (operator==, operator!=), wyświetlanie. Klasa Poly przechowuje tablicę współczynników i implementuje działania.

### Jak uruchomić program:
terminal: make, make run

### Jak to działa?:
Wielomiany w programie reprezentowane są za pomocą tablic dynamicznych (używających wskaźniki). Wielomiany możemy stworzyć na 3 sposoby:

Stworzenie pustego;
stworzenie wielomianu podając jego stopień;
stworzenie wielomianu podając tablicę współczynników i stopnia wielomianu.

Program pozwala nam na wykorzystanie operacji tak jak na wielomianach:
Dodawanie, odejmowanie, mnożenie, porównanie oraz obliczanie wartości dla danego x

### Złożoność obliczeniowa
Stworzenie wielomianu zajmuje O(n) czasu.
Do rozwiązywania Wielomianu posługujemy się algorytmem Hornera, który jest wydajniejszy i szybszy niż klasyczne rozwiązywanie układów wielomianowych.
Zajmuje mu to O(n) czasu dla mnożenia, dodawania i mnożenia, a nie O(n^2) dla mnożenia jak klasyczny algorytm.
