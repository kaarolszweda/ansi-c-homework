#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define STACK_SIZE 6
#define N_OPER 10

void push(double number);
double pop(void);

double stos[STACK_SIZE];
int akt_liczba_arg = 0;

int main(int argc, char *Argv[]){

    char oper[N_OPER];
    double x, y;

    printf("Podaj działanie w ONP: \n");
    while(scanf("%s", oper) == 1){
        if (oper[0] == '-') {
            // Odłóż na stosie liczbę ujemną
            push(-atof(oper + 1));
            continue;
        }
        if(isdigit(oper[0])){
            push(atof(oper));
        } else if(!strcmp(oper, "q") || !strcmp(oper, "Q")) break; //wyjście z kalkulatora
        else {
            if (!strcmp(oper, "+")) {
                // dodawanie
                y = pop();
                x = pop();
                push(x + y);
            } else if (!strcmp(oper, "-")) {
                // odejmowanie
                y = pop();
                x = pop();
                push(x - y);
            } else if (!strcmp(oper, "*")) {
                // mnożenie
                y = pop();
                x = pop();
                push(x * y);
            } else if (!strcmp(oper, "/")) {
                // dzielenie
                y = pop();
                x = pop();
                push(x / y);
            }
            else if (!strcmp(oper, "^")){
                // potęgowanie 
                y = pop();
                x = pop();
                push(pow(x, y));
            } 
            else if (!strcmp(oper, "log")){
                // logarytmy
                y = pop();
                x = pop();
                push(log(y) / log(x));
            } 
            else if (!strcmp(oper, "sin")){
                // sinus
                y = pop();
                x = pop();
                push(sin(y));
            } 
            else if (!strcmp(oper, "cos")){
                // cosinus
                y = pop();
                x = pop();
                push(cos(y));
            } 
            else if (!strcmp(oper, "tan")){
                // tangens
                y = pop();
                x = pop();
                push(tan(y));
            } 
            else if (!strcmp(oper, "=")) {
                // wypisanie ostatniego argumentu ze stosu
                printf("%.2f\n", pop());
            }
             else {
                printf("Nieznany operator: %s\n", oper);
            }
        }
    }
    return 0;
}

void push(double x){
    if (akt_liczba_arg == STACK_SIZE)
    {
        printf("Przekroczono maksymalny rozmiar stosu!\n");
    } else {
        stos[akt_liczba_arg++] = x; 
    }
}
double pop(void){
    if (akt_liczba_arg == 0)
    {
        printf("Stos jest pusty!\n");
        return 1;
    } else {
        return stos[--akt_liczba_arg];
    }
    return 0;
}
