// File mesinkar.h
// definisi mesin karakter

#ifndef MESIN_KAR_H
#define MESIN_KAR_H

#include "boolean.h"

#define MARK '\n'
// state mesin
extern char CC;
extern boolean EOP;
extern boolean EOL;

void STARTFILE(char filename[50]);
/*  Mesin siap digunakan untuk membaca file sesuai dengan nama file yang diberikan.
    I.S.  : nama file terdefinisi
    F.S.  : CC adalah karakter pertama pada file. 
            jika CC != MARK maka EOL akan bernilai False
            jika CC = MARK maka EOL akan bernilai True */

void START();
/*  Mesin siap digunakan untuk membaca input pada stdin.
    I.S.  : sembarang
    F.S.  : CC karakter pertama pada stdin
            jika CC != MARK maka EOP akan bernilai False
            jika CC = MARK maka EOP akan bernilai True */ 

void ADVFILE();
/*  file dimajukan satu karakter.
    I.S. : karakter pada jendela = CC, CC != MARK
    F.S. : CC adalah karakter berikutnya dari CC yang lama, CC mungkin = MARK
           jika CC = MARK maka EOL akan bernilai True
           jika CC = character terakhir dari file, prosedur akan menjalankan fclose(file) */

void ADV();
/*  file dimajukan satu karakter.
    I.S. : karakter pada jendela = CC, CC != MARK
    F.S. : CC adalah karakter berikutnya dari CC yang lama, CC mungkin = MARK
           jika CC = MARK maka EOP akan bernilai True */

#endif