#include <stdio.h>
#include "stackt.h"

int main(){
	Stack S;
	int Elmt,X,idxTop;
	CreateEmpty(&S);
	Menuawal :
	printf("\n=========================\n");
	printf("Stack Menu\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. View Stack\n");
	printf("4. Exit\n");
	printf("Masukkan Pilihan Anda : ");
	scanf("%d",&X);
	switch(X){
		case 1:	printf("\n==================================\n");
				printf("Masukkan Nilai yang akan di Push : "); 
				scanf("%d",&Elmt);
				Push(&S,Elmt);
				goto Menuawal;
				break;
		case 2: printf("\n==================================\n");
				printf("Masukkan Nilai yang akan di Pop : "); 
				scanf("%d",&Elmt);
				Pop(&S,&Elmt);
				goto Menuawal;
				break;
		case 3: printf("\n==================================\n");
				printf("Info Stack \n");
				printf("============\n");
				idxTop = Top(S);
				while(Top(S)!=Nil){	
					printf("%d\n",InfoTop(S));
					Top(S)--;
				}
				Top(S)=idxTop;
				printf("============\n");
				goto Menuawal;
				break;
		case 4: printf("Terimakasih !!");
				break;
		default: printf("wrong input\n");
				break;
	}	
}