// file mesinkata.h
// definisi Mesin Kata dengan model akuisisi *VERSI 2*

#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "boolean.h"
#include "mesinkar.h"

#define NMax 100
#define BLANK ' '

typedef struct {
    char TabKata[NMax+1];
    int length;
} Kata;

// State Mesin Kata
extern Kata CKata;

void IgnoreBlank();
/* mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC != BLANK atau CC = MARK */

void SalinKata(); 
// prosedur digunakan untuk membaca command yang dimasukkan oleh user
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void STARTKATA();
// prosedur digunakan untuk membaca command yang dimasukkan oleh user
/* I.S. : CC sembarang
   F.S. : CKata.length = 0, CC = MARK;
          atau CKata.length != 0, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
// prosedur digunakan untuk membaca command yang dimasukkan oleh user
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
   Proses : Akuisisi kata menggunakan procedure SalinKata */



void SalinKataFILE();
// prosedur digunakan untuk membaca file konfigurasi
/* mengakuisisi kata dalam file konfigurasi dan menyimpan pada CKata
   I.S. : CC berisi karakter pertama pada kata
   F.S. : Ckata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          CKata.length berisi panjang kata yang diakuisisi;
          Karakter pertama pada CKata disimpan pada indeks 0 */

void STARTKATAFILE(char filename[50]);
// prosedur digunakan untuk membaca file konfigurasi
/* I.S. : CC sembarang sesuai dari file konfigurasi
   F.S. : CKata.length = 0, CC = MARK;
          atau CKata.length != 0, CKata adalah kata yang telah diakuisisi
          dengan procedure SalinKataFILE();
          CC adalah karakter pertama sesudah karakter terakhir kata */

void ADVKATAFILE();
// prosedur digunakan untuk membaca file konfigurasi
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi dari file konfigurasi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
   Proses : Akuisisi kata menggunakan procedure SalinKataFILE() */

void newline();
// prosedur digunakan untuk membaca file konfigurasi
/* I.S. : CC adalah MARK '\n'
   F.S. : CC adalah karakter pertama pada baris berikutnya.
   Proses : Prosedur melakukan skip pada MARK untuk melanjutkan 
            pembacaan pada baris berikutnya */

// prosedur/fungsi tambahan

void printKata(Kata kata);
/* I.S. : kata merupakan variabel yang telah terdefinisi dan bertipe Kata
   F.S. : Karakter pada kata berhasil ditampilkan */

int to_Int(char CC);
/* fungsi digunakan untuk melakukan convert pada karakter CC menjadi sebuah integer */

int countresult(Kata kata);
/* fungsi digunakan untuk menghitung nilai integer yang tersimpan pada kata
   dengan asumsi 0 <= kata.length <= 3 dan nilai maksimum yang dapat diakuisisi adalah 999 */

boolean CompStr(char kata1[], char kata2[]);
/* fungsi digunakan untuk melakukan perbandingan antara kata1 dengan kata2;
   fungsi akan mengembalikan nilai true apabila kata1 dan kata2 memiliki isi yang sama
   dan mengembalikan nilai false apabila kata1 dan kata2 berbeda */

#endif