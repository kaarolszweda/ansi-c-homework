#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int day_of_date_J(int day, int month, int year);
int day_of_date_G(int day, int month, int year);
int leap_year(int year);
int num_days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
char *weekdays[] = {"poniedzialek", "wtorek", "sroda", "czwartek", "piatek", "sobota", "niedziela"};


int main(){

    int dzien, miesiac, rok;
    char day[10];
    char month[10];
    char year[10];

    printf("Program obliczający dzień tygodnia.\nPodaj dzień: ");
    scanf("%s", day);
    printf("Podaj miesiąc: ");
    scanf("%s", month);
    printf("Podaj rok: ");
    scanf("%s", year);
    char command[14] = "cal ";

    strcat(command, month);
    strcat(command, " ");
    strcat(command, year);
    system(command);

    printf("Podana data: %s-%s-%s\n", day, month, year);
    int wynikG = day_of_date_G(atoi(day), atoi(month), atoi((year)));
//    int wynikJ = wynikG - 1;
    printf("Gregoriański: %s\n", weekdays[wynikG]);
//    printf("Gregoriański: %s, Juliański: %s\n", weekdays[wynikG], weekdays[wynikJ]);

    return 0;
}
int leap_year_G(int year){
    return ((year % 4 == 0 && year % 100 != 0)|| year % 400 == 0);
}
//int leap_year_J(int year){
//    return (year % 4 == 0);
//}


//todo gregorian
int day_of_date_G(int day, int month, int year){

    int day_of_year, result, yy, c, g;

    day_of_year = day + num_days[month - 1];

    if ((month > 2) && (leap_year_G(year) == 1))
        day_of_year++;
    yy = (year - 1) % 100;
    c = (year - 1) - yy;
    g = yy + (yy / 4);

    result = (((((c / 100) % 4) * 5) + g) % 7);
    result += day_of_year - 1;
    result %= 7;

    return result;
}
//todo julian
//int day_of_date_J(int day, int month, int year){
//
//    int day_of_year, result, yy, c, g;
//
//    day_of_year = day + num_days[month - 1];
//
//    if ((month > 2) && (leap_year_J(year) == 1)){
//        day_of_year++;
//    }
//
//    yy = (year - 1) % 100;
//    c = (year - 1) - yy;
//    g = yy + (yy / 4);
//
//    result = (((((c / 100) % 4) * 5) + g) % 7);
//    result += day_of_year - 1;
//    result %= 7;
//
//    return result;
//}