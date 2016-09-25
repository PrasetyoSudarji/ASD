/* File: point.c */
/* Tanggal: 24 September 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include "point.h"
#include <stdio.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
	POINT P;
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
	float x,y;
	printf("Masukkan Nilai (Absis,Ordinat) \t\n: ");
	scanf ("%f %f",&x,&y);
	*P = MakePOINT(x,y);
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */

void TulisPOINT (POINT P){
	printf("Nilai Absis \t: %.2f \n",Absis(P));
	printf("Nilai Ordinat \t: %.2f \n",Ordinat(P));
}
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
	if (Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2)){
		return true;
	}else{
		return false;
	}

}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

boolean NEQ (POINT P1, POINT P2){
	if (Absis(P1)!=Absis(P2) || Ordinat(P1)!=Ordinat(P2)){
		return true;
	}else{
		return false;
	}
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
	if (Absis(P)==0 & Ordinat(P)==0){
		return true;
	}else{
		return false;
	}
}
/* Menghasilkan true jika P adalah titik origin */

boolean IsOnSbX (POINT P){
	if (Absis(P)==0){
		return true;
	}else{
		return false;
	}
}
/* Menghasilkan true jika P terletak Pada sumbu X */

boolean IsOnSbY (POINT P){
	if (Ordinat(P)==0){
		return true;
	}else{
		return false;
	}
}
/* Menghasilkan true jika P terletak pada sumbu Y */

int Kuadran (POINT P){
	if (Absis(P)>0 && Ordinat(P)>0){
		return 1;
	}else if(Absis(P)<0 && Ordinat(P)>0){
		return 2;
	}else if (Absis(P)<0 && Ordinat(P)<0){
		return 3;
	}else{
		return 4;
	}
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
	POINT hasil;
	Absis(hasil)=Absis(P)+1;
	Ordinat(hasil)=Ordinat(P);
	return hasil;
}
/* Mengirim salinan P dengan absis ditambah satu */

POINT NextY (POINT P){
	POINT hasil;
	Absis(hasil)=Absis(P);
	Ordinat(hasil)=Ordinat(P)+1;
	return hasil;
}
/* Mengirim salinan P dengan ordinat ditambah satu */

POINT PlusDelta (POINT P, float deltaX, float deltaY){
	POINT hasil;
	Absis(hasil)=Absis(P)+deltaX;
	Ordinat(hasil)=Ordinat(P)+deltaY;
	return hasil;
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */

POINT MirrorOf (POINT P, boolean SbX){
	if (SbX==true){
		Ordinat(P)=Ordinat(P)*(-1);
	}else{
		Absis(P)=Absis(P)*(-1);
	}
	return P;
}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */

float Jarak0 (POINT P){
	float hasil;
	hasil = 0.5 * Absis(P) * Ordinat(P);
	if(hasil<0){
		hasil *= -1;
	}
	return hasil;
}
/* Menghitung jarak P ke (0,0) */

void Geser (POINT *P, float deltaX, float deltaY){
	Absis(*P)+=deltaX;
	Ordinat(*P)+=deltaY;
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

void GeserKeSbX (POINT *P){
	Ordinat(*P)=0;
}
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P){
	Absis(*P)=0;
}
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX){
	if (SbX==true){
		Ordinat(*P)=Ordinat(*P)*(-1);
	}else{
		Absis(*P)=Absis(*P)*(-1);
	}
}
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */

/*This file created by @14113003*/