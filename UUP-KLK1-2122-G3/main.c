#include <stdio.h>
#include <math.h>

/*
(6p) Napisati funkciju pom(int arg) koja za prosleđeni broj pronalazi cifru koja se nalazi na sredini
broja. Ukoliko se broj sastoji od parnog broja cifra, vratiti veću srednju cifru.
Napisati program koji ispisuje sve brojeve iz intervala koji korisnik unese ukoliko je broj iz
intervala deljiv kubom svoje srednje cifre.
Primer: Ulaz: 819 1030
Izlaz: 819 824 837 864 910 911 912 913 914 915 916 917 918 919
920 928 1010 1011 1012 1013 1014 1015 1016 1017 1018 1019 1024

(7p) Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu
koja se sastoji od slova, cifara i zagrada. Program ispisuje sumu brojeva. Ako je broj unutar
zagrade formirati novi broj koji se sastoji od parnih pozicija i njega dodati u sumu. Ako je broj
van zagrada ili u ugnježdenim zagradama dodati na sumu obrnuti broj. Napomena, pozicije
cifara u broju računaju se sa leve strane, počevši od 1 (na primer u broju 13579 na poziciji 2
nalazi se cifra 3, na poziciji 4 nalazi se cifra 7).
Primer: Ulaz: md(q2345q(a31b)g141d)a41(sd45a)sad((145sda)1222)g
Izlaz: 634

(7p) Nacrtati sledeću figuru za unetu vrednost n.
Primer za n = 8: Primer za n = 11:

AAAAAAAA AAAAAAAAAAA
bBBBBBBb bBBBBBBBBBb
ccDDDDcc ccDDDDDDDcc
dddGGddd dddGGGGGddd
eeeGGeee eeeeKKKeeee
ffDDDDff fffffPfffff
gBBBBBBg ggggKKKgggg
AAAAAAAA hhhGGGGGhhh
         iiDDDDDDDii
         jBBBBBBBBBj
         AAAAAAAAAAA

*/

int brCif(int arg) {
    int br = 0;
    while (arg > 0) {
        br++;
        arg /= 10;
    }
    return br;
}

int pom(int arg) {
    int oArg = brCif(arg);
    int pozSredCif = brCif(arg) / 2 + 1;
    int izlaz;
    int granica = brCif(arg) - pozSredCif;
    for (int i = 0; i < granica; ++i) {
        arg /= 10;
    }
    if (oArg % 2 == 1) {
        izlaz = arg % 10;
    } else {
        if (arg % 10 > arg / 10 % 10) {
            izlaz = arg % 10;
        } else {
            izlaz = arg / 10 % 10;
        }
    }
    if (izlaz == 0) {
        return INFINITY;
    } else {
        return izlaz;
    }
}

void zad1(int pocetak, int kraj) {
    for (int i = pocetak; i < kraj; ++i) {
        if (i % (pom(i) * pom(i) * pom(i)) == 0) {
            printf("%d\t", i);
        }
    }
}


int trenutnaPoz = 0;
char str[] = "md(q2345q(a31b)g141d)a41(sd45a)sad((145sda)1222)g";

char uzmiKarakter() {
    char vrati = str[trenutnaPoz];
    trenutnaPoz++;
    return vrati;
}

int obrnutBr(int br) {
    int konBr = 0;
    int oBr = brCif(br);
    for (int i = 0; i < oBr; ++i) {
        konBr = konBr * 10 + br % 10;
        br /= 10;
    }
    return konBr;
}

int svakiDrugi(int br) {
    int izlaz = 0;
    int oBr = brCif(br);
    for (int i = 0; i < oBr; ++i) {
        if (i % 2 == 0) {
            izlaz = izlaz * 10 + br / (int) pow(10, oBr - i - 1) % 10;
        }

    }
    return izlaz;
}
/*int trenutnaPoz = 0;
char str[] = "md(q2345q(a31b)g141d)a41(sd45a)sad((145sda)1222)g";*/
int zad2() {
    int zagrade = 0;
    int sum = 0;
    char c;
    while ((c = uzmiKarakter()) != 0) {
        if(c>=49&&c<=57){
            int trenutniBr = 0;
            while (c >= 49 && c <= 57) {
                trenutniBr = trenutniBr * 10 + c-48;
                c = uzmiKarakter();
            }
            if (zagrade == 1) {
                sum += svakiDrugi(trenutniBr);
            } else {
                sum += obrnutBr(trenutniBr);
            }
        }
        if (c == '(') {
            zagrade++;
        } else if (c == ')') {
            zagrade--;
        }
    }
    return sum;
}

int main() {
    //printf("%d", svakiDrugi(12345));
    //printf("%d", zad2());
    
    return 0;
}
