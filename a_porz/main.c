
//TODO
// Porządkowanie alfabetyczne. Proszę napisać program, który wczytuje kolejne wiersze tekstu wprowadzanego
// ze standardowego wejścia, aż do napotkania znacznika końca pliku (przy wprowadzaniu z klawiatury: Ctrl-D),
// zapamiętuje je w tablicy char *Tekst[N_MAX]; gdzie N_MAX to pewna ustalona maksymalna liczba wierszy,
// a następnie porządkuje wiersze w kolejności alfabetycznej i wyprowadza wynik na standardowe wyjście.
// Zadanie można stosunkowo łatwo wykonać korzystają z funkcji qsort(...) oraz strcmp(...) zdefiniowanych w plikach
// nagłówkowych <stdlib.h> i <string.h>. Do wczytywania kolejnych wierszy doskonale nadaje się funkcja standardowa
// fgets(...); warto zadbać o to, aby puste wiersze były pomijane na etapie wczytywania.

#define N_MAX 10

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sort_string( const void *str1, const void *str2);
void sortutil(char* lines[], int count);

int main(){

    char *Tekst[N_MAX];
    char buffer[100];
    int counter = 0;
    int i = 0;

    printf("Wczytaj wiersze tekstu: \n");
    while( i < N_MAX && fgets(buffer, 100, stdin) != NULL){
        Tekst[i] = strndup(buffer, 100);
        if (Tekst[i] != NULL){
            counter++;
        }
        i++;
    }
    printf("\nPosortowane  alfabetycznie: \n");
    sortutil(Tekst, counter);
    for(int i = 0; i < counter; i++){
        printf("%s", Tekst[i]);
    }

    return 0;
}

int sort_string( const void *str1, const void *str2){
    char *const *pp1 = str1;
    char *const *pp2 = str2;
    return strcmp(*pp1, *pp2);
}
void sortutil(char* lines[], int count){
    qsort(lines, count, sizeof(*lines), sort_string);
}