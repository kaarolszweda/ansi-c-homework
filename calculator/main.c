#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 6
#define N_OPER 10

void push(double number);
double pop(void);

// char dzialanie[NUMBER_OF_STRINGS][MAX_STRING_SIZE];
double liczby[MAXSIZE];
int akt_liczba_arg = 0;
char oper[N_OPER];

int main(int argc, char *Argv[]){
    printf("Podaj działanie w ONP: \n");
    for(int i = 0; i < N_OPER; i++){
        scanf("%s", oper);
    }
    
    

    // int ilosc_dzialan = 0;

    


    // printf("Podaj działanie w ONP: ");
    // for (int i = 0; i < NUMBER_OF_STRINGS; i++)
    // {
    //     scanf("%s", dzialanie[i]);
    //     // if (dzialanie[i] != '\n'){
    //     //     ilosc_dzialan++;
    //     // }
    // }

    // for (int i = 0; i < NUMBER_OF_STRINGS; i++){
    //     printf("%s ", dzialanie[i]);
    // }
    return 0;

}
int isempty() {

   if(akt_liczba_arg == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(akt_liczba_arg == MAXSIZE)
      return 1;
   else
      return 0;
}
void push(double number){
    if (isfull)
    {
        printf("Przekroczono maksymalny rozmiar stosu!\n");
    } else {
        
    }
    
}
double pop(void){
    if (isempty)
    {
        printf("Stos jest pusty!");
    } else {
        
    }
    return 0;
}
