/* Implementasi Mesin Kata Versi I */
#include "mesinkata.h"

boolean EndKata; /* penanda akhir akuisisi kata */
Kata CKata;      /* kata yang sudah diakuisisi dan akan diproses */

void Ignore_Blank()
/* Mengabaikan satu atau beberapa BLANK */
/* I.S. : CC sembarang */
/* F.S. : CC ≠ BLANK atau CC = MARK */
{ /* Kamus Lokal */

	/* Algoritma */
	while (CC == BLANK && CC != MARK) {
		ADV();
	} /* CC != BLANK or CC = MARK */
}

void STARTKATA()
/* I.S. : CC sembarang */
/* F.S. : EndKata = true, dan CC = Mark; */
/*        atau EndKata = false, CKata adalah kata yang sudah
		  diakuisisi,
		  CC karakter pertama sesudah karakter terakhir kata */
{ /* Kamus Lokal */

	/* Algoritma */
	START();
	Ignore_Blank();
	if (CC == MARK) {
		EndKata = true;
	} else { /* CC != MARK */
		EndKata = false;
		SalinKata();
	}
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi */
/* F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
		  CC adalah karakter pertama sesudah karakter terakhir
	      kata */
/* Proses : Akuisisi kata menggunakan void SalinKata */

{ /* Kamus Lokal */

	/* Algoritma */
	Ignore_Blank();
	if (CC == MARK) {
		EndKata = true;
	} else { /* CC != MARK */
		SalinKata();
	}
}


void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata 
/* I.S. : CC adalah karakter pertama dari kata 
/* F.S. : CKata berisi kata yang sudah diakuisisi; CC = BLANK atau
		  CC = MARK;
		  CC adalah karakter sesudah karakter terakhir yang
		  diakuisisi */
{ /* Kamus Lokal */
	int i;
	
	/* Algoritma */
	i = 1;
	CKata.TabKata[1] = CC;
	ADV();
	while (CC != MARK && CC != BLANK) {
		i = i + 1;
		CKata.TabKata[i] = CC;
		ADV();
	} /* CC = MARK or CC = BLANK */
	CKata.Length = i; 
}

/*
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata 
/* I.S. : CC adalah karakter pertama dari kata 
/* F.S. : CKata berisi kata yang sudah diakuisisi; CC = BLANK atau
		  CC = MARK;
		  CC adalah karakter sesudah karakter terakhir yang
		  diakuisisi 
{ /* Kamus Lokal 
	int i;
	
	/* Algoritma 
	i = 1;
	CKata.TabKata[1] = CC;
	ADV();
	while (CC != MARK && CC != BLANK && i < NMax) {
		i = i + 1;
		CKata.TabKata[i] = CC;
		ADV();
	} /* CC = MARK or CC = BLANK or i = NMax 
	CKata.Length = i; 
}
*/

boolean IsKataSama(Kata K1,Kata K2){
	/*Menghasilkan true jika K1 = K2*/
	/*Kamus Lokal */
	int i;
	
	// Algoritma
	if (K1.Length != K2.Length){
		return false;
	}else{
		i=1;
		while((i<K1.Length) && (K1.TabKata[i] == K2.TabKata[i])){
			i+=1;
		}
		return (K1.TabKata[i] == K2.TabKata[i]);
	}
}

