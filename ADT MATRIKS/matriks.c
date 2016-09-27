/* File: matriks.c */

/* ********** Definisi ADT MATRIKS dengan indeks dan elemen integer ********** */

#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
} 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Pengecekan Indeks Matriks *** */
boolean IsIdxValid (int i, int j){
	if (i>0 && j>0){
		return true;
	}else{
		return false;
	}
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
	if ((i>BrsMin && i<NBrsEff(M)) && (j>KolMin && j<NKolEff(M))){
		return true;
	}
	else{
		return false;
	}
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
	*MHsl=MIn;
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
	indeks i,j;
	
	MakeMATRIKS(NB,NK,&*M);
	for (i=BrsMin;i<=NBrsEff(*M);i++){
		for (j=KolMin;j<=NKolEff(*M);j++){
			printf("[%d][%d] : ",i,j);
			scanf("%d",&Elmt(*M,i,j));
		}
	}
}
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M){
	indeks i,j;
	
	for (i=BrsMin;i<=NBrsEff(M);i++){
		for (j=KolMin;j<=NKolEff(M);j++){
			printf("%d\t",Elmt(M,i,j));
		}
		printf("\n");
	}
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom, 
           masing-masing baris diakhiri enter */
/* Contoh: menulis matriks 3x3 (masing-masing baris diakhiri enter)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
	MATRIKS Mhasil;
	NBrsEff(Mhasil)=NBrsEff(M1);
	NKolEff(Mhasil)=NKolEff(M1);
	indeks i,j;
	for(i=BrsMin;i<=NBrsEff(Mhasil);i++){
		for(j=KolMin;j<=NKolEff(Mhasil);j++){
			Elmt(Mhasil,i,j)=Elmt(M1,i,j)+Elmt(M2,i,j);
		}
	}
	return Mhasil;
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
	MATRIKS Mhasil;
	NBrsEff(Mhasil)=NBrsEff(M1);
	NKolEff(Mhasil)=NKolEff(M2);
	indeks i,j;
	for(i=BrsMin;i<=NBrsEff(Mhasil);i++){
		for(j=KolMin;j<=NKolEff(Mhasil);j++){
			Elmt(Mhasil,i,j)=Elmt(M1,i,j)-Elmt(M2,i,j);
		}
	}
	return Mhasil;
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
	MATRIKS Mhasil;
	NBrsEff(Mhasil)=NBrsEff(M1);
	NKolEff(Mhasil)=NKolEff(M1);
	indeks i,j;
	int k;
	for(i=BrsMin;i<=NBrsEff(Mhasil);i++){
		for(j=KolMin;j<=NKolEff(Mhasil);j++){
			Elmt(Mhasil,i,j)=0;
			for(k=BrsMin;k<=NKolEff(M1);k++){
				Elmt(Mhasil,i,j)+=(Elmt(M1,i,k)*Elmt(M2,k,j));
			}
		}
	}
	return Mhasil;
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */


MATRIKS KaliKons (MATRIKS M, ElType X){
	int i,j;
	for(i=BrsMin;i<=NBrsEff(M);i++){
		for(j=KolMin;j<=NKolEff(M);j++){
			Elmt(M,i,j)*=X;	
		}
	}
	return M;
}
/* Mengirim hasil perkalian setiap elemen M dengan X */

void PKaliKons (MATRIKS * M, ElType K){
	int i,j;
	for(i=BrsMin;i<=NBrsEff(*M);i++){
		for(j=KolMin;j<=NKolEff(*M);j++){
			Elmt(*M,i,j)*=K;
		}
	}
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
	boolean cek=true;
	
	indeks i=BrsMin,j=KolMin;
	while(i<=NBrsEff(M1) &&  cek==true){
		while(j<=NKolEff(M1) &&  cek==true){	
			if (Elmt(M1,i,j)!=Elmt(M2,i,j)){
				cek=false;
			}
			j++;
		}
		i++;
	}
	
	return cek;
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1[i][j] = M2[i][j] */

boolean NEQ (MATRIKS M1, MATRIKS M2){
	boolean cek=false;
	
	indeks i=BrsMin,j=KolMin;
	while(i<=NBrsEff(M1) && cek==false){
		while(j<=NKolEff(M1) && cek==false){	
			if (Elmt(M1,i,j)!=Elmt(M2,i,j)){
				cek = true;
			}
			j++;
		}
		i++;
	}
	
	return cek;
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */

boolean EQSize (MATRIKS M1, MATRIKS M2){
	if(NBrsEff(M1)==NBrsEff(M2) && NKolEff(M1)==NKolEff(M2)){
		return true;
	}else{
		return false;
	}
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NbElmt (MATRIKS M){
	return NBrsEff(M)*NKolEff(M);
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
	if(NBrsEff(M)==NKolEff(M)){
		return true;
	}else{
		return false;
	}
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */

boolean IsSimetri (MATRIKS M){
	boolean cek=true;
	indeks i=BrsMin,j=KolMin;
	if(IsBujurSangkar(M)==true){
		while(i<=NBrsEff(M) && cek==true){
			while(j<=NKolEff(M) && cek==true){	
				if (Elmt(M,i,j)!=Elmt(M,j,i)){
					cek = false;
				}
				j++;
			}
			i++;
		}
	}else{
		cek=false;
	}
	return cek;
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M[i][j]=M(j,i) */
   
boolean IsSatuan (MATRIKS M){
	indeks i=BrsMin,j=KolMin;
	boolean cek=true;
	if (IsBujurSangkar(M)){
		while(i<=NBrsEff(M) && cek!=false){
			while(j<=NKolEff(M) && cek!=false){
				if(i==j){
					if(Elmt(M,i,j)==1){
						cek = true;
					}else{
						cek = false;
					}
				}else{
					if(Elmt(M,i,j)==0){
						cek = true;
					}else{
						cek = false;
					}
				}
				j++;
			}
			i++;
		}
	}else{
		cek=false;
	}
	return cek;
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
   
boolean IsSparse (MATRIKS M){
	indeks i,j;
	float sparse=0;
	for (i=BrsMin;i<=NBrsEff(M);i++){
		for(j=KolMin;j<=NKolEff(M);j++){
			if(Elmt(M,i,j)!=0){
				sparse+=1;
			}
		}
	}
	int size=NBrsEff(M)*NKolEff(M);
	float hasil= sparse/size;
	if(hasil<=0.05){
		return true;
	}else{
		return false;
	}
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
   
MATRIKS Inverse1 (MATRIKS M){
	MATRIKS Mhasil;
	indeks i,j;
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&Mhasil);
	for (i=BrsMin;i<=NBrsEff(Mhasil);i++){
		for(j=KolMin;j<=NKolEff(Mhasil);j++){
			Elmt(Mhasil,i,j)=Elmt(M,i,j)*(-1);
		}
	}
	return Mhasil;
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */

float Determinan (MATRIKS M){
	indeks i=BrsMin,j=KolMin;
	
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */

void PInverse1 (MATRIKS * M){
	indeks i,j;
	for (i=BrsMin;i<=NBrsEff(*M);i++){
		for(j=KolMin;j<=NKolEff(*M);j++){
			Elmt(*M,i,j)=Elmt(*M,i,j)*(-1);
		}
	}
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

void Transpose (MATRIKS * M){
	indeks i,j;
	for (i=BrsMin;i<=NBrsEff(*M);i++){
		for(j=KolMin;j<=NKolEff(*M);j++){
			Elmt(*M,i,j)=Elmt(*M,j,i);
		}
	}
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M[i][j] ditukar nilainya dengan elemen M[j][i] */

/*This file created by @14113003*/