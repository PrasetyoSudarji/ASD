#include <stdio.h>
#include "point.h"

int main(){
	POINT P,P1,P2;
	printf("==================================\n");
	BacaPOINT(&P);
	TulisPOINT(P);
	printf("==================================\n");
	printf("Read P1\n");
	BacaPOINT(&P1);
	printf("Read P2\n");
	BacaPOINT(&P2);
	if(EQ(P1,P2)==true){
		printf("P1 & P2 Equivalent\n");
	}
	if(NEQ(P1,P2)==true){
		printf("P1 & P2 Not Equivalent\n");
	}
	printf("==================================\n");
	printf("Check Origin P\n");
	if(IsOrigin(P)==true){
		printf("P Origin\n");
	}else if(IsOnSbX(P)==true){
		printf("P is on Sumbu X\n");
	}else if(IsOnSbY(P)==true){
		printf("P is on Sumbu Y\n");
	}else{
		printf("P isn't Origin or On Sb X or On Sb Y\n");
	}
	printf("==================================\n");
	printf("Check Quadrant\n");
	printf("Please input P(P isnt origin, or on Sb X or on Sb Y)\n");
	BacaPOINT(&P);
	if(Kuadran(P)==1 ){
		printf("P  is on First Quadrant\n");
	}else if(Kuadran(P)==2){
		printf("P is on Second Quadrant\n");
	}else if(Kuadran(P)==3){
		printf("P is on Third Quadrant\n");
	}else if(Kuadran(P)==4){
		printf("P is on Fourth Quadrant\n");
	}else{
		printf("P is on Origin\n");
	}
	printf("==================================\n");
	printf("You can try The other Function or Procedure by Yourself\n");
	printf("Thank You and Follow me on Github : https://github.com/14113003\n");
	
	
	return 0;
	
}
