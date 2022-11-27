#include <stdio.h>
#include <stdlib.h>

int Konwersja_Dec_Bin(unsigned dec, char* bin);
int Konwersja_Dec_Bin_B(unsigned dec, char* bin);

int main(int argc, char *argv[]) {

//    int *ptr = (int*)malloc(n * sizeof(int));
    unsigned int dec;
    int metoda = atoi(argv[1]);
    char bin[10] = "";

    printf("Podaj liczbę dziesiętną: ");
    scanf("%d", &dec);

    if (metoda == 1){
        printf("WERSJA A (standardowe operatory): ");

        int counter = Konwersja_Dec_Bin(dec, bin);
        for (int i = counter; i >= 0; i--){
            printf("%c", bin[i]);
        }
        printf("\n");
    }  else if (metoda == 2){
        printf("WERSJA B (przesunięcie bitowe): ");
        int counter = Konwersja_Dec_Bin_B(dec, bin);

        for (int i = 30; i >= 0; i--){
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
    return i;
}

int Konwersja_Dec_Bin_B(unsigned dec, char* bin){
    int size = (sizeof(dec));
    for (int i = 32; i >= 0; i--) {
        int x = dec >> i;
        if (x & 1) bin[i] = '1';
        else bin[i] = '0';
    }
    return 0;
}
