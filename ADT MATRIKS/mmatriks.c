#include <stdio.h>
#include "matriks.h"

int main(){
	MATRIKS M,Mhasil,M1,M2;
	int NB,NK,NBM1,NBM2,NKM1,NKM2;
	boolean cek;
	printf("==============================\n");
	printf("NB : ");
	scanf("%d",&NB);
	printf("NK : ");
	scanf("%d",&NK);
	printf("==============================\n");
	BacaMATRIKS(&M,NB,NK);
	printf("==============================\n");
	TulisMATRIKS(M);
	printf("==============================\n");
	printf("Copy Matriks\n");
	CopyMATRIKS(M,&Mhasil);
	TulisMATRIKS(Mhasil);
	printf("==============================\n");
	printf("Tambah Matriks\n");
	TulisMATRIKS(TambahMATRIKS(M,Mhasil));
	printf("==============================\n");
	printf("Kurang Matriks\n");
	TulisMATRIKS(KurangMATRIKS(M,Mhasil));
	printf("==============================\n");
	printf("Kali Matriks\n");
	printf("M1 : \n");
	BacaMATRIKS(&M1,NB,NK);
	printf("M2 : \n");
	BacaMATRIKS(&M2,NB,NK);
	printf("Hasil :\n");
	TulisMATRIKS(KaliMATRIKS(M1,M2));
	printf("==============================\n");
	printf("Cek Equivalnt with EQ()\n");
	BacaMATRIKS(&M1,NB,NK);
	printf("==============================\n");
	BacaMATRIKS(&M2,NB,NK);
	cek = NEQ(M1,M2);
	if(cek==false){
		printf("Equivalent\n");
	}else{
		printf("Not Equivalent\n");
	}
	printf("==============================\n");
	printf("Cek Equivalnt with NEQ()\n");
	BacaMATRIKS(&M1,NB,NK);
	printf("==============================\n");
	BacaMATRIKS(&M2,NB,NK);
	cek = NEQ(M1,M2);
	if(cek==false){
		printf("Equivalent\n");
	}else{
		printf("Not Equivalent\n");
	}
	printf("==============================\n");
	printf("Cek Equivalnt Sieze \n");
	printf("NB M1 : ");
	scanf("%d",&NBM1);
	printf("NK M1 : ");
	scanf("%d",&NKM1);
	BacaMATRIKS(&M1,NBM1,NKM1);
	printf("==============================\n");
	printf("NB M2 : ");
	scanf("%d",&NBM2);
	printf("NK M2 : ");
	scanf("%d",&NKM2);
	BacaMATRIKS(&M2,NBM2,NKM2);
	cek = EQSize(M1,M2);
	if(cek==false){
		printf("Equivalent\n");
	}else{
		printf("Not Equivalent\n");
	}
	
	printf("==============================\n");
	printf("Cek Simetri\n");
	printf("NB : ");
	scanf("%d",&NB);
	printf("NK : ");
	scanf("%d",&NK);
	BacaMATRIKS(&M,NB,NK);
	cek = IsSimetri(M);
	if(cek==true){
		printf("Simetri\n");
	}else{
		printf("Not Simetri\n");
	}
	
	printf("==============================\n");
	printf("Cek is Satuan\n");
	printf("NB : ");
	scanf("%d",&NB);
	printf("NK : ");
	scanf("%d",&NK);
	BacaMATRIKS(&M,NB,NK);
	cek = IsSatuan(M);
	if(cek==true){
		printf("is Satuan\n");
	}else{
		printf("is Not Satuan\n");
	}
	
	printf("==============================\n");
	printf("Cek Invers Matriks\n");
	printf("NB : ");
	scanf("%d",&NB);
	printf("NK : ");
	scanf("%d",&NK);
	BacaMATRIKS(&M,NB,NK);
	TulisMATRIKS(M);
	printf("Matriks inversnya \n");
	Mhasil = Inverse1(M);
	TulisMATRIKS(Mhasil);
	
	printf("==============================\n");
	printf("Cek Transpose Matriks\n");
	printf("NB : ");
	scanf("%d",&NB);
	printf("NK : ");
	scanf("%d",&NK);
	BacaMATRIKS(&M,NB,NK);
	TulisMATRIKS(M);
	printf("Matriks Transpose \n");
	Transpose(&M);
	TulisMATRIKS(M);
	
	return 0;
	
}