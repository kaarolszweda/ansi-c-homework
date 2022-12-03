#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int find_max(long int a, long int b);
int find_len(long int num);
long int karatsuba(long int x, long int y);

int main() {
    long int x, y;

    printf("Program obliczający duże liczby naturalne.\n");
    printf("Podaj liczbę x: ");
    scanf("%ld", &x);
    printf("Podaj liczbę y: ");
    scanf("%ld", &y);

    int dlugosc = find_len(x);
    printf("Długość liczby x: %d\n", dlugosc);


    long int wynik = karatsuba(x, y);
    printf("Wynik wynosi: %ld\n", wynik);

    return 0;
}
int find_max(long int a, long int b){
    return (a > b) ? a : b;
}
int find_len(long int num){
    int result = 0;
    do {
        num /= 10;
        ++result;

    } while (num != 0);
    return result;
}
//https://www.youtube.com/watch?v=yWI2K4jOjFQ
long int karatsuba(long int x, long int y){
    if (x < 10 || y < 10){
        return x * y;
    } else {
        long int n = find_max(find_len(x), find_len(y));
        long int half = n / 2;

        long int a = x / pow(10, half);
        printf("A: %ld | ", a);
        long int b = x % (long int)pow(10, half);
        printf("B: %ld | ", b);
        long int c = y / pow(10, half);
        printf("C: %ld | ", c);
        long int d = y % (long int)pow(10, half);
        printf("D: %ld | ", d);

        long int ac = karatsuba (a, c);
        printf("AC: %ld | ", ac);
        long int bd = karatsuba (b, d);
        printf("BD: %ld | ", bd);

        long int ad_plus_bc = (karatsuba (a + b, c + d) - ac - bd);
        printf("AD+BC %ld | ", ad_plus_bc);
        long int wynik = ac * (pow(10, (2 * half)) + (ad_plus_bc * pow(10, half)) + bd);
        printf("WYNIK %ld | ", wynik);

        return ac * (pow(10, (2 * half)) + (ad_plus_bc * pow(10, half)) + bd);
    };
}