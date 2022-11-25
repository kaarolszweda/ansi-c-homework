#include <stdlib.h>
#include <stdio.h>

int FindPrimesUpToN(int n);

int main(){
    printf("Program znajdujący wszystkie liczby pierwsze mniejsze od zadanej wartości\n");
    FindPrimesUpToN(70);

    return 0;
}

int FindPrimesUpToN(int n){
    char* arr = (char*) malloc(n*sizeof (char));
//    char arr[n + 1];

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