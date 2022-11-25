#include <stdio.h>
#include <stdlib.h>

int Konwersja_Dec_Bin(unsigned dec, char* bin);
int Konwersja_Dec_Bin_B(unsigned dec, char* bin);

int main(int argc, char *argv[]) {

    int *ptr = (int*)malloc(n * sizeof(int));
    unsigned int dec;
    int metoda = atoi(argv[1]);
    char bin[10] = "";

    printf("Podaj liczbę dziesiętną: ");
    scanf("%d", &dec);

    if (metoda == 1){
        printf("WERSJA A (standardowe operatory): ");
        Konwersja_Dec_Bin(dec, bin);

        //https://www.educative.io/answers/how-to-use-malloc-in-c
        for (int i = 9; i >= 0; i--){
            printf("%c", bin[i]);
        }
        printf("\n");
    }  else if (metoda == 2){
        printf("WERSJA B (przesunięcie bitowe): ");
        Konwersja_Dec_Bin_B(dec, bin);

        for (int i = 6; i >= 0; i--){
            printf("%c", bin[i]);
        }
    }

    return 0;
}

int Konwersja_Dec_Bin(unsigned dec, char* bin){
    int i = 0;
    while(dec > 0){
        bin[i] = (dec % 2)+'0';
        dec = dec / 2;
        i++;
    }
    return 0;
}

int Konwersja_Dec_Bin_B(unsigned dec, char* bin){

    // Size of an integer is assumed to be 32 bits
    for (int i = 10; i >= 0; i--) {

        int x = dec >> i; // right shift

        if (x & 1) bin[i] = '1'; /* helps us know the state of first bit*/
        else bin[i] = '0';
    }
    return 0;
}
