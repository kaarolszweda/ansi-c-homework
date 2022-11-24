#include <stdio.h>
#include <stdlib.h>

unsigned int licz_dwumian_i(int n, int k);
unsigned int licz_dwumian_r(int n);
int binomialCoeff(int n, int k);

void print_pascal(int n){
    int arr[n][n];
    for (int line = 0; line < n; line++)
    {
        // Every line has number of integers
        // equal to line number
        for (int i = 0; i <= line; i++)
        {
            // First and last values in every row are 1
            if (line == i || i == 0)
                arr[line][i] = 1;
                // Other values are sum of values just
                // above and left of above
            else
                arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
};



int main(int argc, char *argv[]) {

//    int metoda, n, dwumian_i, dwumian_r;
//
//    metoda = atoi(argv[1]);
//    n = atoi(argv[2]);
//
//
//    if(metoda == 1){
//        dwumian_i = licz_dwumian_i(n);
//        printf("Dwumian iteracyjnie wynosi: %d\n", dwumian_i);
//    }else if (metoda == 2){
//        dwumian_r = licz_dwumian_r(n);
//        printf("Dwumian rekurencyjnie wynosi: %d\n", dwumian_r);
//    }
//    else return 1;
    print_pascal(5);
    int wynik = binomialCoeff(256, 4);

    printf("%d", wynik);

    return 0;
}
int binomialCoeff(int n, int k)
{
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
unsigned int licz_dwumian_i(int n, int k){
    int result = 1;
    int tab[n][n];
    for ( int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

unsigned int licz_dwumian_r(int n){
    if(n < 2)
        return 1;
    return n* licz_dwumian_r(n-1);
}