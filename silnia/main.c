#include <stdio.h>
#include <stdlib.h>

double licz_silnia_i(int n);
double licz_silnia_r(int n);

int main(int argc, char *argv[]) {

    int metoda, n;
    double silnia_i, silnia_r;

    metoda = atoi(argv[1]);
    n = atoi(argv[2]);


    if(metoda == 1){
        silnia_i = licz_silnia_i(n);
        printf("Silnia iteracyjnie wynosi: %f\n", silnia_i);
    }else if (metoda == 2){
        silnia_r = licz_silnia_r(n);
        printf("Silnia rekurencyjnie wynosi: %f\n", silnia_r);
    }
    else return 1;

    return 0;
}
// usigned int max n = 12
// double int max n = 170
double  licz_silnia_i(int n){
    double wynik = 1;
    for ( int i = 1; i <= n; i++){
        wynik *= i;
    }
    return wynik;
}

double licz_silnia_r(int n){
    if(n < 2)
        return 1;
    return n* licz_silnia_r(n-1);
}