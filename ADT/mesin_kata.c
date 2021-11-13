/* NIM : 18220028 */
/* Nama : Muhammad Dzaki Dwi Putranto */
/* Tanggal : 22 September 2021 */
/* Topik Praktikum : Praktikum 3 */
/* Deskripsi : implementasi mesin_kata.h */

#include "mesin_kata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank() {
    /*ALGORITMA */
    while (CC == BLANK) {
        ADV();
    }
}

void SalinKata() {
    /* KAMUS LOKAL */
    int i;
    /*ALGORITMA */
    i = 1;
    while ((CC != MARK) && (CC != BLANK)) {
        CKata.TabKata[i] = CC;
        ADV();
        i ++;
    }
    CKata.Length = i-1;
}

void STARTKATA() {
    /* ALGORITMA */
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    }
    else {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA() {
    /* ALGORITMA */
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    }
    else {
        SalinKata();
    }
}