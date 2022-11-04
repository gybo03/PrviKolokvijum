#include <stdio.h>
#include <math.h>


/*
 1. Napisati funkciju pom(int arg) koja vrada najvedu razliku između susednih cifara argumenta
(pretpostavimo da argument uvek ima bar dve cifre). Zatim ispisati sve brojeve iz intervala koji unosi
korisnik a kojima je najveda razlika između cifara manja od 3.

2. Koristedi naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu karaktera
koja počinje brojem a sastoji se od brojeva i znakova + i -, tako da se izračuna i ispiše rezultat
aritmetičkih operacija sabiranja i oduzimanja koje se izvršavaju redom.
primer: 10+13-12+25-5+100
rezultat: 131

3. Nacrtati slededu figuru za unetu visinu n (n<=9), primeri:

n=6 n=5 n=3 n=1
123456  shift=0,kraj=n
121212
234561  shift=1,kraj=n-1
232323
345612  shift=2,kraj=n-2
343434

12345
12121
23451
23232
34512

123
121
231

1

 */

int pom(int br) {
    int trenutnaR = 0;
    int maxR = 0;
    int prviC;
    int drugaC;
    while (br > 10) {
        prviC = br % 10;
        br /= 10;
        drugaC = br % 10;
        trenutnaR = abs(prviC - drugaC);
        if (trenutnaR > maxR) {
            maxR = trenutnaR;
        }
    }
    return maxR;
}

void zad1(int pocetak, int kraj) {
    for (int i = pocetak; i <= kraj; ++i) {
        if (pom(i) < 3) {
            printf("%d\n", i);
        }
    }
}

int zad2a(char str[]) {
    int rez = 0, br = 0, c, i = 0, znak;
    while (str[i] >= '0' && str[i] <= '9') {
        br = br * 10 + str[i] - '0';
        i++;
    }
    if (i > 0) {
        rez += br;
    }
    while (str[i] != 0) {
        if (str[i] == '-') {
            znak = -1;
            br = 0;
        } else if (str[i] == '+') {
            znak = 1;
            br = 0;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            br = br * 10 + str[i] - '0';
            if (str[i + 1] < '0' || str[i + 1] > '9') {
                rez = rez + znak * br;
                br = 0;
            }
        }
        i++;
    }
    return rez;
}

int zad2c() {
    int rez = 0, br = 0, i = 0, znak;
    char c;

    while ((c = getchar()) >= '0' && c <= '9') {
        br = br * 10 + c - '0';
        i++;
    }
    if (i > 0) {
        rez += br;
        br = 0;
    }
    while (c != 10) {
        if (c >= '0' && c <= '9') {
            br = br * 10 + c - '0';

        } else {
            rez = rez + znak * br;
            br = 0;
        }

        if (c == '-') {
            znak = -1;
        } else if (c == '+') {
            znak = 1;
        }
        c = getchar();
    }
    rez = rez + znak * br;
    return rez;
}

void zad3(int n) {
    int shift = 0, temp=0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = shift; j < n; ++j) {
                printf("%d", j + 1);
            }
            for (int j = 0; j < shift; ++j) {
                printf("%d", j + 1);
            }
            shift++;
        } else {
            temp=shift;
            for (int j = 0; j < n; ++j) {
                if(temp<=shift+1){
                    printf("%d",temp);
                    temp++;
                }  else{
                    temp=shift;
                    j--;
                }
            }
        }
        printf("\n");
    }
}


int main() {
    //printf("%d", pom(3149));
    //zad1(10, 100);
    //zad2c();
    //zad3(9);

    return 0;
}
