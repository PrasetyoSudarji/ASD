#include "mesinkata.h"
#include <stdio.h>

int main() {
	/* KAMUS */
	Kata KataYOU; //kata yang menyimpang YOU
	int NYOU; 	//banyaknya kata YOU
	KataYOU.TabKata[1]='y';
	KataYOU.TabKata[2]='o';
	KataYOU.TabKata[3]='u';
	KataYOU.Length = 3;
	NYOU = 0;
	
	/* ALGORITMA */
	STARTKATA();
	while(!EndKata) {
		if(IsKataSama(KataYOU,CKata)){
			NYOU+=1;
		}
		ADVKATA();
	}
	
	printf("banyak kata you adalah : %d\n",NYOU);
	
	return 0;
}