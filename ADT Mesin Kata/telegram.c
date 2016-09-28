#include "mesinkata.h"
#include <stdio.h>

int main(){
	int NHuruf = 0,j,NKoma=0,NTitik=0,NKata=0;
	float biaya=0;
	Kata Koma;
	Kata Titik;
	Koma.TabKata[1]='K';
	Koma.TabKata[2]='O';
	Koma.TabKata[3]='M';
	Koma.TabKata[4]='A';
	Koma.Length=4;
	
	Titik.TabKata[1]='T';
	Titik.TabKata[2]='I';
	Titik.TabKata[3]='T';
	Titik.TabKata[4]='I';
	Titik.TabKata[5]='K';
	Titik.Length=5;
	
	int a=0, b=0;
	
	STARTKATA();
	while(!EOP || !EndKata){
		
		printf(" ");
		if(CC==BLANK){
			if(CKata.Length<10 && !IsKataSama(Koma,CKata) && !IsKataSama(Titik,CKata)){
				a++;
				biaya+=1000;
			}else if(CKata.Length>=10 && !IsKataSama(Koma,CKata) && !IsKataSama(Titik,CKata)){
				b++;
				biaya+=1500;
			}
		}
		NKata+=1;
		
		if(IsKataSama(Titik,CKata)){
			CKata.TabKata[1]='.';
			CKata.Length=1;
		}
		
		if(IsKataSama(Koma,CKata)){
			CKata.TabKata[1]=',';
			CKata.Length=1;
		}
		
		for(j=1;j<=CKata.Length;j++){
			printf("%c",CKata.TabKata[j]);
		}
		ADVKATA();
	}
	
	if(NKata>=10){
		biaya-=0.1*biaya;
	}
	
	printf("\n%d",a);
	printf("\n%d",b);
	printf("\n%.0f",biaya);
	
	
}