//TODO
// Porządkowanie alfabetyczne. Proszę napisać program, który wczytuje kolejne wiersze tekstu wprowadzanego
// ze standardowego wejścia, aż do napotkania znacznika końca pliku (przy wprowadzaniu z klawiatury: Ctrl-D),
// zapamiętuje je w tablicy char *Tekst[N_MAX]; gdzie N_MAX to pewna ustalona maksymalna liczba wierszy,
// a następnie porządkuje wiersze w kolejności alfabetycznej i wyprowadza wynik na standardowe wyjście.
// Zadanie można stosunkowo łatwo wykonać korzystają z funkcji qsort(...) oraz strcmp(...) zdefiniowanych w plikach
// nagłówkowych <stdlib.h> i <string.h>. Do wczytywania kolejnych wierszy doskonale nadaje się funkcja standardowa
// fgets(...); warto zadbać o to, aby puste wiersze były pomijane na etapie wczytywania

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N_MAX 10

int sort_string_inc( const void *str1, const void *str2);
int sort_string_dec( const void *str1, const void *str2);
void sortutil_inc(char* lines[], int count);
void sortutil_dec(char* lines[], int count);

int main(int argc, char *argv[]){

    int metoda = atoi(argv[1]);
    char *Tekst[N_MAX];
    char buffer[100];

    //Wczytywanie tekstu
    int counter = 0;
    int i = 0;
    printf("Wczytaj wiersze liczby: \n");
    while( i < N_MAX && fgets(buffer, 100, stdin) != NULL){
        Tekst[i] = strndup(buffer, 100);
        if (Tekst[i] != NULL){
            counter++;
            i++;
        }
    }

    if(metoda == 1){
        printf("\nPosortowane rosnąco: \n");
        sortutil_inc(Tekst, counter);
    } else {
        printf("\nPosortowane malejąco: \n");
        sortutil_dec(Tekst, counter);
    }

    //Wypisanie alfabetycznie uporządkowanie tekstu
    for(int i = 0; i < counter; i++){
        printf("%s", Tekst[i]);
    }

    return 0;
}

int sort_string_inc( const void *str1, const void *str2){
    char *const *pp1 = str1;
    char *const *pp2 = str2;
    return strcmp(*pp1, *pp2);
}
int sort_string_ddec( const void *str1, const void *str2){
    char *const *pp1 = str1;
    char *const *pp2 = str2;
    return -strcmp(*pp1, *pp2);
}
void sortutil_inc(char* lines[], int count){
    qsort(lines, count, sizeof(*lines), sort_string_inc);
}void sortutil_dec(char* lines[], int count){
    qsort(lines, count, sizeof(*lines), sort_string_dec);
}