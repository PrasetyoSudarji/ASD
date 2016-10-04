#include "queue.h"
#include "stdio.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
	return ((Head(Q)==NIL) && (Tail(Q)==Nil));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
	return ((Head(Q)==1) && (Tail(Q)==Max(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (Queue Q){
	return (Tail(Q)-Head(Q)+1);
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
	(*Q).T = (infotype*) malloc ((Max+1) * sizeof(infotype));
	if((*Q).T != NULL){
		MaxEl (*Q) = Max;
		Head (*Q) = Nil;
		Tail (*Q) = Nil;
	}else{
		MaxEl(*Q) = 0;
	}
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
	MaxEl (*Q) = 0;
	free ((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
	address i,j;
	
	if(IsEmpty(*Q)){
		Head(*Q) = 1;
	} else{
		if (Tail(*Q) == MaxEl(*Q)){ /* Geser elemen smp Head(Q)=1*/
			i = Head((*Q);
			j = 1;
			do{
				*((*Q).T+j = *((*Q).T+i);
				i++;
				j++;
			}while (i<=Tail(*Q));
		}
		Tail(*Q) = NBElmt(*Q);
		Head(*Q) = 1;
	}
	Tail(*Q)++;
	InfoTail(*Q) = X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (Queue * Q, infotype * X){
	*X = InfoHead(*Q);
	if (Head(*Q)==Tail(*Q)) { /* Set mjd queue kosong */
		Head(*Q)=Nil; Tail(*Q)=Nil;
	}else {
		Head(*Q)++;
	}
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
