#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int licz_dwumian_i(int n, int k);
int licz_dwumian_r(int n, int k);
double gen_rozkl(int k, int n, float p);

int main(int argc, char *argv[]) {
    //gnuplot prepare
    int n_plot = 0;
    double p_plot = 0.5;
    FILE *fp = NULL;
    FILE *gnupipe = NULL;
    char *GnuCommands[] = {"set title \"Rozkład prawdopodobieństwa Bernoulliego\"", "plot 'data.tmp'"};

    fp = fopen("data.tmp", "w");
    gnupipe = popen("gnuplot -persistant", "w");

    //binomial
    int metoda, n, k;
    double dwumian_i, dwumian_r;

    metoda = atoi(argv[1]);
    n = atoi(argv[2]);
    k = atoi(argv[3]);

    if(metoda == 1){
        dwumian_i = licz_dwumian_i(n, k);
        printf("Dwumian iteracyjnie wynosi: %f\n", dwumian_i);
    }else if (metoda == 2){
        dwumian_r = licz_dwumian_r(n, k);
        printf("Dwumian rekurencyjnie wynosi: %f\n", dwumian_r);
    }
    else return 1;

    //passing gnuplot values
    double wynik;
    for (int i = 0; i <= 12; i++){
        wynik = gen_rozkl(i, n, 0.5);
        fprintf(fp, "%d %f\n", i, wynik);
        n_plot++;
    }

    for (int i = 0; i < 2; i++){
        fprintf(gnupipe, "%s\n",  GnuCommands[i]);
    }
    return 0;
}

int min(int a, int b){
    return (a > b) ? b : a;
}

int licz_dwumian_i(int n, int k){
    int C[k + 1];
    for (int i = 0; i < (k + 1); i++){
        C[i] = 0;
    }
    C[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = min(i, k); j > 0; j--){
            C[j] = C[j] + C[j-1];
        }
    }
    return C[k];
}

int licz_dwumian_r(int n, int k){
    if (k == 0 || k == n)
        return 1;
    return licz_dwumian_r(n - 1, k - 1) + licz_dwumian_r(n - 1, k);
}

double gen_rozkl(int k, int n, float p){
    double wynik = licz_dwumian_r(n, k)*pow(p, k)*pow((1 - p), n - k);
    printf("%f | ", wynik);
    return wynik;
}