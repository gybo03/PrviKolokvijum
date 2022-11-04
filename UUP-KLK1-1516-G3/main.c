#include <stdio.h>
#include <math.h>
#include <string.h>

/*
Napisati funkciju pom koja izračunava broj koji se dobija uklanjanjem prve i
poslednje cifre argumenta. Napraviti zbir brojeva koji se dobijaju primenom
funkcije na brojeve koje unosi korisnik ( korisnik unosi brojeve dok ne unese
nula).

Koristeći naredbu while za obradu teksta, ispisati trocifren broj koji se sastoji od 3
poslednje cifre u ulaznom tekstu.
primer: ABC3DF5HFD6GFD7
rezultat: 567

Nacrtati sledeću figuru za unetu visinu n. Primer je za n=5:
 11111
1 2222
12 333
1 2222
 11111
*/

int pom(int ulaz) {
    int izlaz = ulaz, temp = 0;
    while (ulaz > 10) {
        temp++;
        ulaz /= 10;
    }
    izlaz = (izlaz - ulaz * pow(10, temp)) / 10;
    return izlaz;
}

int zad1() {
    int zbir = 0;
    int ulaz;
    do {
        scanf("%d", &ulaz);
        zbir += pom(ulaz);
    } while (ulaz != 0);
    return zbir;
}

void zad2(char str[]) {
    int br = 0, count = 0;
    int i = strlen(str);
    while (str[i] != str[0] && count < 3) {
        if (str[i] >= 48 && str[i] <= 57) {
            br = br + (str[i] - 48) * pow(10, count);
            count++;
        }
        i--;
    }
    printf("%d", br);
}

void zad3(int n) {
    int temp = n / 2;;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i <= n / 2) {
                if (j < i) {
                    printf("%d", j + 1);
                } else {
                    printf("%d", i + 1);
                }
            } else {
                if (j < temp) {
                    printf("%d", j + 1);
                } else {
                    printf("%d", temp + 1);
                }
            }
        }
        if (i >= n / 2) {
            temp--;
        }
        printf("\n");
    }
}

int main() {
    //printf("%d\n",pom(1234));
    //printf("%d\n",zad1());
    //zad2("ABC3DF5HFD6GFD7");
    //zad3(5);
    return 0;
}
