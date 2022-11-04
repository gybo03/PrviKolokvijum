#include <stdio.h>

/*
Napisati funkciju pom koja vraca koliko broj ima parnih cifara. Sabrati sve
neparne rezultate koje vraca funkcija za brojeve koje unosi korisnik ( korisnik
unosi brojeve dok ne unese nula).
primer: 12 22 426 0
rezultat: 4 (1+0+3)

Koristeći naredbu while za obradu teksta, ispisati tekst kao u primeru.
primer: abcdefghijklmnopq
rezultat: abCDefGHijKLmnOPq

Nacrtati sledeću figuru za unetu visinu n. Primer je za n=5:
AA...
BBB..
.CCC.
..DDD
...EE

*/

int pom(int ulaz) {
    int brParnih = 0;
    while (ulaz > 0) {
        if (ulaz % 2 == 0) {
            brParnih++;
        }
        ulaz /= 10;
    }
    return brParnih;
}

int zad1() {
    int zbir = 0;
    int ulaz = 1;
    while (ulaz != 0) {
        scanf("%d", &ulaz);
        if (pom(ulaz) % 2 == 1) {
            zbir += pom(ulaz);
        }
    }
    return zbir;
}

void zad2(char str[]) {
    int i = 0;
    int korak = 0;
    while (str[i] != 0) {
        if (korak <= 3) {
            if (korak <= 1) {
                printf("%c", str[i]);
            } else {
                printf("%c", str[i] - 32);
            }
            korak++;
        } else {
            korak = 0;
            i--;
        }
        i++;
    }
}

void zad3(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || i + 1 == j || i == j + 1) {
                printf("%c", i + 65);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    //printf("%d\n", pom(1234));
    //printf("%d\n", zad1());
    //zad2("abcdefghijklmnopq");
    zad3(15);
    return 0;
}
