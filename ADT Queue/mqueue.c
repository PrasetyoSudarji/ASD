#include <stdio.h>
#include "queue.h"

int main(){
	Queue Q;
	int Elmt,X,idxHead,Max;
	
	printf("Tentukan Max Queue : \n");
	scanf("%d",&Max);
	CreateEmpty(&Q,Max);
	Menuawal :
	printf("\n=========================\n");
	printf("Queue Menu\n");
	printf("1. Add\n");
	printf("2. Dell\n");
	printf("3. View Queue\n");
	printf("4. Exit\n");
	printf("Masukkan Pilihan Anda : ");
	scanf("%d",&X);
	switch(X){
		case 1:	printf("\n==================================\n");
				printf("Masukkan Nilai yang akan di Add : "); 
				scanf("%d",&Elmt);
				Add(&Q,Elmt);
				goto Menuawal;
				break;
		case 2: printf("\n==================================\n");
				Del(&Q,&Elmt);
				printf("Deleting Success\n");
				goto Menuawal;
				break;
		case 3: printf("\n==================================\n");
				printf("Info Queue \n");
				printf("============\n");
				idxHead = Head(Q);
				while(Head(Q)!=Tail(Q)){
					printf("%d\n",InfoHead(Q));
					Head(Q)++;
				}
				Head(Q)=idxHead;
				printf("============\n");
				goto Menuawal;
				break;
		case 4: printf("Terimakasih !!");
				break;
		default: printf("wrong input\n");
				break;
	}	
}