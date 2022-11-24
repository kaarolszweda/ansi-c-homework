#include <stdio.h>

int nwd(int m, int n);

int main() {

    int m, n;
    printf("Program szukający NWD.\nPodaj m: ");
    scanf("%d", &m);
    printf("Podaj n: ");
    scanf("%d", &n);

    int wynik = nwd(m, n);

    printf("NWD wynosi: %d\n", wynik);
    return 0;
}
int nwd(int m, int n){
    if(n == 0) return m;
    else if(m >= n ){
        while(n != 0){
            int reszta = m % n;
            m = n;
            n = reszta;
        }
    }
    return m;
}