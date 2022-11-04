#include <stdio.h>
#include <math.h>

/*
Napisati funkciju pom koja proverava da li argument ima sve cifre manje od 5.
Koristeći tu funkciju, pomnožiti sve parne brojeve u intervalu koji unosi korisnik,
a da zadovoljavaju traženo svojstvo.

Koristeći naredbu while za obradu teksta izbaciti svako slovo koje je susedno
prethodno ispisanom slovu (susedna=slova koja se nalaze jedno pored drugog u
ASCII tabeli) iz unetog teksta.
primer: AbDfghjk
rezultat: ADfj

Nacrtati sledeću figuru za unetu visinu n. Primer je za n=5:
<<<<<
->>>-
--<--
->>>-
<<<<<
*/

int uslov1(int ulaz) {
    while (ulaz > 0) {
        if ((ulaz % 10) >= 5) {
            return 0;
        }
        ulaz = ulaz / 10;
    }
    return 1;
}

int zad1(int pocetak, int kraj) {
    int proizvod = 1;
    for (int i = pocetak; i <= kraj; ++i) {
        if (uslov1(i) == 1 && (i % 2 == 0)) {
            printf("%d\t", i);
            proizvod = proizvod * i;
        }
    }
    printf("\n");
    return proizvod;
}

void zad2(char niz[]) {
    printf("ulaz = %s\n", niz);
    int i = 1;
    printf("%c", niz[0]);
    while (niz[i] != 0) {
        if (abs(niz[i] - niz[i - 1]) == 1 || abs(niz[i] - niz[i - 1]) == 33 || abs(niz[i] - niz[i - 1]) == 31) {
            int j = i + 1;
            while (abs(niz[i - 1] - niz[j]) == 1 || abs(niz[i - 1] - niz[j]) == 33 || abs(niz[i] - niz[j]) == 31) {
                j++;
            }
            i = j;
        } else {
            printf("%c", niz[i]);
            i++;
        }

    }
    printf("\n");
}

void zad2a(char niz[]) {
    printf("ulaz = %s\n", niz);
    int i = 0;
    printf("%c", niz[i]);
    while (niz[i] != 0) {
        int j = i + 1;
        while (abs(niz[i] - niz[j]) == 1 || abs(niz[i] - niz[j]) == 33 || abs(niz[i] - niz[j]) == 31) {
            j++;
        }
        if (niz[j] != 0) {
            i = j;
        }
        printf("%c", niz[i]);
        i++;
    }


    printf("\n");
}

void zad3(int velicina) {

    for (int i = 0; i < (velicina+1) / 2; ++i) {
        if (i % 2 == 1) {
            for (int j = 0; j < i; ++j) {
                printf("-");
            }
            for (int j = i; j < velicina - i; ++j) {
                printf("<");
            }
            for (int j = 0; j < i; ++j) {
                printf("-");
            }
            printf("\n");
        } else {
            for (int j = 0; j < i; ++j) {
                printf("-");
            }
            for (int j = i; j < velicina - i; ++j) {
                printf(">");
            }
            for (int j = 0; j < i; ++j) {
                printf("-");
            }
            printf("\n");
        }
    }
    for (int i = velicina / 2-1; i >= 0; --i) {
        if (i % 2 == 1) {
            for (int j = i; j > 0; --j) {
                printf("-");
            }
            for (int j = velicina - i; j > i; --j) {
                printf("<");
            }
            for (int j = i; j > 0; --j) {
                printf("-");
            }
            printf("\n");
        } else {
            for (int j = i; j > 0; --j) {
                printf("-");
            }
            for (int j = velicina - i; j > i; --j) {
                printf(">");
            }
            for (int j = i; j > 0; --j) {
                printf("-");
            }
            printf("\n");
        }
    }
}

int main() {
    /*
    printf("r=%d\n", zad1(1, 10));
    printf("r=%d\n", zad1(100, 110));
    printf("r=%d\n", zad1(5, 10));

    zad2("AbDfghjk");
    zad2a("BACDF");//bdf

    zad3(6);
    zad3(5);
    */
    return 1;
}
