# Projekt zaliczeniowy : AiSD I
### Temat projekt:

Implementacja wielomianów na bazie tablic (szablon, współczynniki typu T). Działania na wielomianach: dodawanie (operator+), odejmowanie (operator-), mnożenie (operator*), sprzężenie, porównywanie (operator==, operator!=), wyświetlanie. Klasa Poly przechowuje tablicę współczynników i implementuje działania.

### Jak uruchomić program:
terminal: make, make run

### Co robi program?:
Wielomiany w programie reprezentowane są za pomocą tablic dynamicznych (używających wskaźniki).

Program pozwala nam na wykorzystanie operacji tak jak na wielomianach:
Dodawanie, odejmowanie, mnożenie, wyświetlanie, sprawdzanie czy wielomian jest zerowy oraz obliczanie wartości dla danego x.

### Złożoność obliczeniowa
Stworzenie wielomianu zajmuje O(n) czasu.
Do rozwiązywania Wielomianu posługujemy się algorytmem Hornera, który jest wydajniejszy i szybszy niż klasyczne rozwiązywanie układów wielomianowych.
Zajmuje mu to O(n) czasu dla mnożenia, dodawania i mnożenia, a nie O(n^2) dla mnożenia jak klasyczny algorytm.
