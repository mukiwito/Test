// file mesinkata.c
// implementasi mesinkata.h

#include "mesinkata.h"
#include <stdio.h>
#include <string.h>

Kata CKata;

void IgnoreBlank() {
/*  mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang
    F.S. : CC != BLANK atau CC = MARK */

    /* ALGORITMA */
    while (CC == BLANK) {
        ADV();
    }
}

void SalinKata() {
//  prosedur digunakan untuk membaca command yang dimasukkan oleh user
/*  Mengakuisisi kata, menyimpan dalam CKata
    I.S. : CC adalah karakter pertama dari kata
    F.S. : CKata berisi kata yang sudah diakuisisi;
           CC = BLANK atau CC = MARK;
           CC adalah karakter sesudah karakter terakhir yang diakuisisi.
           Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0; 
    while ((CC != MARK) && (CC != BLANK)) {
        CKata.TabKata[i] = CC; // karakter pertama pada CKata disimpan pada indeks 0
        ADV();
        i = i + 1;
    }
    CKata.length = i;
}

void STARTKATA() {
// prosedur digunakan untuk membaca command yang dimasukkan oleh user
/*  I.S. : CC sembarang
    F.S. : CKata.length = 0, dan CC = MARK;
           atau CKata.length != 0, CKata adalah kata yang sudah diakuisisi,
           CC karakter pertama sesudah karakter terakhir kata */

    /* ALGORITMA */
    START();
    IgnoreBlank();
    SalinKata();
}

void ADVKATA() {
//  prosedur digunakan untuk membaca command yang dimasukkan oleh user
/*  I.S.  :  CC adalah karakter pertama kata yang akan diakuisisi
    F.S.  :  CKata adalah kata terakhir yang sudah diakuisisi,
            CC adalah karakter pertama dari kata berikutnya, mungkin MARK
   Proses : Akuisisi kata menggunakan procedure SalinKata */

    /* ALGORITMA */
    IgnoreBlank();
    SalinKata();
}

void SalinKataFILE() {
// prosedur digunakan untuk membaca file konfigurasi
/* mengakuisisi kata dalam file konfigurasi dan menyimpan pada CKata
   I.S. : CC berisi karakter pertama pada kata
   F.S. : Ckata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          CKata.length berisi panjang kata yang diakuisisi;
          Karakter pertama pada CKata disimpan pada indeks 0 */

    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0;
    while ((CC != MARK) && (CC != BLANK)) {
        CKata.TabKata[i] = CC; // karakter pertama pada CKata disimpan pada indeks 0
        ADVFILE();
        i = i + 1;
    }
    CKata.length = i;
}

void STARTKATAFILE(char filename[50]) {
// prosedur digunakan untuk membaca file konfigurasi
/* I.S. : CC sembarang sesuai dari file konfigurasi
   F.S. : CKata.length = 0, CC = MARK;
          atau CKata.length != 0, CKata adalah kata yang telah diakuisisi
          dengan procedure SalinKataFILE();
          CC adalah karakter pertama sesudah karakter terakhir kata */

    /* ALGORITMA */
    STARTFILE(filename);
    IgnoreBlank();
    SalinKataFILE();
}

void ADVKATAFILE() {
// prosedur digunakan untuk membaca file konfigurasi
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi dari file konfigurasi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
   Proses : Akuisisi kata menggunakan procedure SalinKataFILE() */

    /* ALGORITMA */
    IgnoreBlank();
    SalinKataFILE();
}

void newline() {
// prosedur digunakan untuk membaca file konfigurasi
/* I.S. : CC adalah MARK '\n'
   F.S. : CC adalah karakter pertama pada baris berikutnya.
   Proses : Prosedur melakukan skip pada MARK untuk melanjutkan 
            pembacaan pada baris berikutnya */

    /* ALGORITMA */
    if (CC = MARK) {
        printf("\n");
        ADVFILE();
    }
}


// PROSEDUR/FUNGSI TAMBAHAN

void printKata(Kata kata) {
/* I.S. : kata merupakan variabel yang telah terdefinisi dan bertipe Kata
   F.S. : Karakter pada kata berhasil ditampilkan */

    /* ALGORITMA */
    for (int i=0 ; i<kata.length ; i++) {
        printf("%c", kata.TabKata[i]);
    }
    printf(" ");
}

int to_Int(char CC) {
/* fungsi digunakan untuk melakukan convert pada karakter CC menjadi sebuah integer */

    /* ALGORITMA */
    switch (CC) {
        case '0' :
			return 0;
		case '1' :
			return 1;
		case '2' :
			return 2;
		case '3' :
			return 3;
		case '4' :
			return 4;
		case '5' :
			return 5;
		case '6' :
			return 6;
		case '7' :
			return 7;
		case '8' :
			return 8;
		case '9' :
			return 9;
    }
}

int countresult(Kata kata) {
/* fungsi digunakan untuk menghitung nilai integer yang tersimpan pada kata
   dengan asumsi 0 <= kata.length <= 3 dan nilai maksimum yang dapat diakuisisi adalah 999 */

    /* KAMUS LOKAL */
    int result;
    /* ALGORITMA */
    if (kata.length == 3) {
        result =100*(to_Int(kata.TabKata[0])) + 10*(to_Int(kata.TabKata[1])) + to_Int(kata.TabKata[2]);
    }
    else if (kata.length == 2) {
        result =10*(to_Int(kata.TabKata[0])) + to_Int(kata.TabKata[1]);
    }
    else if (kata.length == 1) {
        result = to_Int(kata.TabKata[0]);
    }
    return result;
}

boolean CompStr(char kata1[], char kata2[]) {
/* fungsi digunakan untuk melakukan perbandingan antara kata1 dengan kata2;
   fungsi akan mengembalikan nilai true apabila kata1 dan kata2 memiliki isi yang sama
   dan mengembalikan nilai false apabila kata1 dan kata2 berbeda */

    /* KAMUS LOKAL */
    boolean same;
    int i;
    /* ALGORITMA */
    same = true;
    if ((strlen(kata1)) != (strlen(kata2))) {
        same = false;
    }
    else {
        i = 0;
        while ((i < strlen(kata1)) && same) {
            if (kata1[i] != kata2[i]) {
                same = false;
            }
            i = i + 1;
        }
    }
    return same;
}