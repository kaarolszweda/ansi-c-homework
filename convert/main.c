#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct RZYM {
    int arab;
    char *rzym;
}  rz[]={{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},
         {40,"XL"},{50,"L"},{90,"XC"},{100,"C"},
         {400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}
int main() {

    printf("Program konwertujący liczbę arabską na rzymską i na odwrót.\n");

    char number[4] = "0000";
    printf("Podaj liczbę: ");
    scanf("%s", number);

    int roman = isalpha(number[0]);
    int digit = isdigit(number[0]);

    if (roman) {

        int res = 0;

        for (int i = 0; i < strlen(number); i++) {

            int s1 = value(number[i]);
            if (i + 1 < strlen(number)) {
                // Getting value of symbol s[i+1]
                int s2 = value(number[i + 1]);

                // Comparing both values
                if (s1 >= s2) {
                    // Value of current symbol
                    // is greater or equal to
                    // the next symbol
                    res = res + s1;
                } else {
                    // Value of current symbol is
                    // less than the next symbol
                    res = res + s2 - s1;
                    i++;
                }
            } else {
                res = res + s1;
            }
        }
        printf("%d", res);
    }

    if (digit)
    {
        int number_a = atoi(number);
        if (number_a >= 0 && number_a < 4000)
        {
            char *roman_s = (char *) malloc(sizeof (number_a)* 10 );
            int i = 12;
            while (number_a) {
                while (number_a < rz[i].arab)
                    i--;
                while(number_a >= rz[i].arab) {
                    strcat(roman_s, rz[i].rzym);
                    number_a -= rz[i].arab;
                }
            }
            printf("%s", roman_s);
            free(roman_s);
        }
    }
    return 0;
}
