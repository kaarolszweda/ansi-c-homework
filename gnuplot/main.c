#include <stdio.h>

int main() {

    int x = 0, y = 0;
    FILE *fp = NULL;
    FILE *gnupipe = NULL;
    char *GnuCommands[] = {"set title \"DEMO\"", "plot 'data.tmp'"};

    fp = fopen("data.tmp", "w");
    gnupipe = popen("gnuplot -persistant", "w");

    for (int i = 0; i < 11; i++){
        fprintf(fp, "%d %d\n", x, y);
        x++;
        y++;
    }

    for (int i = 0; i < 2; i++){
        fprintf(gnupipe, "%s\n",  GnuCommands[i]);
    }


    return 0;
}
