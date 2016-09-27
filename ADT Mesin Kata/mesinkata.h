/* Primitif Mesin Kata */
#ifndef _MESIN_KATA_H_
#define _MESIN_KATA_H_
#include "mesinkar.h"

/* ***** Konstanta ***** */
#define BLANK ' '
#define NMax 50

/* ***** Definisi Type Kata ***** */
typedef struct { 
	char TabKata[NMax+1];
	int Length;
} Kata;

/* 	TabKata adalah tempat penampung/container kata, 
	Length menyatakan panjangnya kata */
/* 	Memori array yang dipakai selalu dimulai dari indeks ke-1 */

/* ***** Definisi State Mesin Kata ***** */
extern boolean EndKata; /* penanda akhir akuisisi kata */
extern Kata CKata;      /* kata yang sudah diakuisisi dan akan diproses */

/* ***** Primitif-Primitif Mesin Kata ***** */
void Ignore_Blank();
/* Mengabaikan satu atau beberapa BLANK */
/* I.S. : CC sembarang */
/* F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA();
/* I.S. : CC sembarang */
/* F.S. : EndKata = true, dan CC = Mark; */
/*        atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
		  CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi */
/* F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
		  CC adalah karakter pertama sesudah karakter terakhir kata */
/* Proses : Akuisisi kata menggunakan void SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata */
/* I.S. : CC adalah karakter pertama dari kata */
/* F.S. : CKata berisi kata yang sudah diakuisisi; 
		  CC = BLANK atau CC = MARK; 
		  CC adalah karakter sesudah karakter terakhir yang diakuisisi */
		  
boolean IsKataSama(Kata K1,Kata K2);
/*	I.S. : CC sembarang
	F.S. : Menghasilkan true jika K1 = K2
*/
#endif