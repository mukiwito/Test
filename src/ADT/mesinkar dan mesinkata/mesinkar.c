// file mesinkar.c
// implementasi mesin karakter

#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;
boolean EOL;

static FILE * file;
static int retval;

void STARTFILE(char filename[50]) {
/*  Mesin siap digunakan untuk membaca file sesuai dengan nama file yang diberikan.
    I.S.  : nama file terdefinisi
    F.S.  : CC adalah karakter pertama pada file. 
            jika CC != MARK maka EOL akan bernilai False
            jika CC = MARK maka EOL akan bernilai True */ 

    /* ALGORITMA */
    file = fopen(filename,"r");
    ADVFILE();   
}

void ADVFILE() {
/*  file dimajukan satu karakter.
    I.S. : karakter pada jendela = CC, CC != MARK
    F.S. : CC adalah karakter berikutnya dari CC yang lama, CC mungkin = MARK
           jika CC = MARK maka EOL akan bernilai True
           jika CC = character terakhir dari file, prosedur akan menjalankan fclose(file) */

    /* ALGORITMA */
    retval = fscanf(file, "%c", &CC);
    EOL = (CC == MARK);
    if (EOL) {
        EOP = (retval != 1);
        if (EOP) {
            fclose(file);
        }
    }
}

void START() {
/*  Mesin siap digunakan untuk membaca input pada stdin.
    I.S.  : sembarang
    F.S.  : CC karakter pertama pada stdin
            jika CC != MARK maka EOP akan bernilai False
            jika CC = MARK maka EOP akan bernilai True */ 

    /* ALGORITMA */
    file = stdin;
    ADV();
}

void ADV() {
    /*  file dimajukan satu karakter.
    I.S. : karakter pada jendela = CC, CC != MARK
    F.S. : CC adalah karakter berikutnya dari CC yang lama, CC mungkin = MARK
           jika CC = MARK maka EOP akan bernilai True */

    /* ALGORITMA */
    retval = fscanf(file, "%c", &CC);
    EOP = (CC == MARK);
    if (EOP) {
        fclose(file);
    }
}