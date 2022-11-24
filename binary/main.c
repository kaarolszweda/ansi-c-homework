#include <stdio.h>

int Konwersja_Dec_Bin(unsigned dec, char* bin);
int Konwersja_Dec_Bin_B(unsigned dec, char* bin);

int main() {

    unsigned int dec;
    char bin[10] = "";
    char bins[10] = "";

    printf("Podaj liczbę dziesiętną: ");
    scanf("%d", &dec);
    Konwersja_Dec_Bin(dec, bin);

    for (int j = 9; j >= 0; j--){
        printf("%c", bin[j]);
    }
    printf("\n");


    Konwersja_Dec_Bin_B(dec, bins);

    for (int j = 6; j >= 0; j--){
        printf("%c", bins[j]);
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
