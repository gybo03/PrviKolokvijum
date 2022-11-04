#include <stdio.h>

#include <stdlib.h>
#include <conio.h>

/*
Napisati funkciju pom koja proverava da li je argument veći od obrnutog broja.
Koristeći tu funkciju, sabrati sve brojeve koji unosi korisnik (kraj je kada se unese
nula), a da zadovoljavaju traženo svojstvo.

Koristeći naredbu while za obradu teksta ,ispisati tekst na način prikazan u
primeru.
primer: 10A3B1C
rezultat: AAAAAAAAAABBBC

Nacrtati sledeću figuru za unetu visinu n. Primer je za n=5:
–-C--
--CD-
-BCD-
-BCDE
ABCDE
*/

int pom(int arg) {
    int pocetniBr = arg;
    int obrnutBr = 0;
    while (arg > 0) {
        obrnutBr = obrnutBr * 10 + arg % 10;
        arg /= 10;
    }
    if (pocetniBr >= obrnutBr) {
        return 1;
    } else {
        return 0;
    }
}

int zad1() {
    int zbir = 0;
    int unos = 1;
    while (unos != 0) {
        scanf("%d", &unos);
        if (pom(unos) == 1) {
            zbir += unos;
        }
    }
    return zbir;
}

void zad2(char ulaz[]) {
    int i = 0;
    int tekuciBr = 0;
    char tekuceSlovo;
    while (ulaz[i] != 0) {
        while ((int) (ulaz[i]) >= 48 && (int) (ulaz[i]) <= 57) {
            tekuciBr = tekuciBr * 10 + ulaz[i] - 48;
            i++;
        }
        tekuceSlovo = ulaz[i];
        while (tekuciBr > 0) {
            printf("%c", tekuceSlovo);
            tekuciBr--;
        }
        i++;
    }
}

void zad3(int n) {
    int pivot, minPivot;
    if (n % 2 == 0) {
        pivot = n / 2 - 1;
    } else {
        pivot = n / 2;
    }
    int maxPivot=pivot;

    for (int i = 0; i < n; ++i) {
        //printf("%d %d %d", pivot,minPivot,maxPivot);
        if (i % 2 == 1) {
            pivot += i;
            maxPivot=pivot;
        } else {
            pivot -= i;
            minPivot = pivot;
        }
        for (int j = 0; j < n; ++j) {
            if (j >= minPivot&&j<=maxPivot) {
                printf("%c", 65 + j);
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int main() {
    //printf("%d\n", zad1());
    //zad2("10A3B1C");
    //zad3(5);
    return 0;
}
