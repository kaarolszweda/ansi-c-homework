#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double licz_silnia_i(int n);
double licz_silnia_r(int n);

int main(int argc, char *argv[]) {

    int metoda, n;
    double silnia_i, silnia_r;

    metoda = atoi(argv[1]);
    n = atoi(argv[2]);
    clock_t t;
    double time_taken;
    if(metoda == 1){

        t = clock();
        silnia_i = licz_silnia_i(n);
        t = clock() - t;
        printf("Silnia iteracyjnie wynosi: %f\n", silnia_i);
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("%f sekundy", time_taken);

    }else if (metoda == 2){
        t = clock();
        silnia_r = licz_silnia_r(n);
        t = clock() - t;
        printf("Silnia rekurencyjnie wynosi: %f\n", silnia_r);
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("%f sekundy", time_taken);
    }
    else return 1;

    return 0;
}
// usigned int max n = 12cd
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