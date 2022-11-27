#include <stdlib.h>
#include <stdio.h>

int znajdz_liczby_pierwsze(int n);

int main(){
    printf("Program znajdujący wszystkie liczby pierwsze mniejsze od zadanej wartości\n");

    int zakres;
    printf("Podaj wartość zakres poszukiwanych liczb pierwszych: ");
    scanf("%d", &zakres);

    znajdz_liczby_pierwsze(zakres);

    return 0;
}

int znajdz_liczby_pierwsze(int n){
    char* arr = (char*) malloc(n*sizeof (char));

    //Uzupełnienie całej tablicy wartościami 1
    for (int i = 0; i <= n; i++){
        arr[i] = '1';
    }

    for(int a = 2; a * a <= n; a++){
        if (arr[a] == '1'){
            for ( int i = a * a; i <= n; i += a){
                arr[i] = '0';
            }
        }
    }

    for (int p = 2; p <= n; p++)
        if (arr[p] == '1')
            printf("%d ",p);
    return 0;
}