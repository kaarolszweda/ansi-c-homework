#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10
int main(int argc, char *Argv[]){

    if (argc != 2) {
        printf("Niepoprawna liczba argumentów!\n");
        return 1;
    }

    FILE *file1;
    FILE *file2;

    char znak;
    char haslo[MAX_LEN];
    char Tymczasowy[] = "/tmp/tempfileXXXXXX";
    int temp_fd;

    temp_fd = mkstemp(Tymczasowy);
    if (temp_fd == -1) {
        return 1;
    }

    printf("Podaj hasło szyfrujące podany plik: ");
    fgets(haslo, MAX_LEN, stdin);
    
    int dlugosc_hasla = strlen(haslo);//haslo + 1 np. karol = 6

    if (NULL==(file1=fopen(Argv[1],"rb"))) return 1;

    if (NULL==(file2=fopen(Tymczasowy,"wb"))) return 1;

    int j = 0;
    while ((znak = getc(file1)) != EOF) {
        znak ^= haslo[ j % (dlugosc_hasla) ];
        putc(znak, file2);
        j++;
    }

    fclose(file1);
    fclose(file2);

    remove(Argv[1]); //remove is portable, and unlink is Unix-specific.
    rename(Tymczasowy, Argv[1]);

    return 0;
}
