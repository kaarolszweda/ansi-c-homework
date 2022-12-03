#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int find_max(int a, int b);
int karatsuba(int x, int y);

int main() {
    //add user input char
    char a[10] = "";
    char b[10] = "";
    int x, y;

    printf("Program obliczający duże liczby naturalne.\n");
    printf("Podaj liczbę x: ");
    scanf("%d", &x);
    printf("Podaj liczbę y: ");
    scanf("%d", &y);

    long int wynik = karatsuba(x, y);
    printf("Wynik wynosi: %ld", wynik);
    return 0;
}
int find_max(int a, int b){
    return (a > b) ? a : b;
}
//https://www.youtube.com/watch?v=yWI2K4jOjFQ

int karatsuba(int x, int y){
    if (x < 10 || y <10){
        return x * y;
    } else {

        int n = find_max(floor(log10(abs(x))), floor(log10(abs(y))) );
        int half = floor(n / 2);

        int a = floor(x / pow(10, half));
        int b = x % (int)pow(10, half);
        int c = floor(y / pow(10, half));
        int d = y % (int)pow(10, half);

        int ac = karatsuba(a, c);
        int bd = karatsuba(b, d);

        int ad_plus_bd = karatsuba(a + b, c + d) - ac - bd;
        return ac * (pow(10, (2 * half)) + (ad_plus_bd * pow(10, half)) + bd);
    }
}