#include <stdio.h>
#include <stdlib.h>

int licz_dwumian_i(int n, int k);
int licz_dwumian_r(int n, int k);

int main(int argc, char *argv[]) {

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