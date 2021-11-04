#include<stdio.h>
#include<math.h>

int main(){
	int a, b;
	printf("Nhap a = ", a);
	scanf("%d" , &a);
	printf("Nhap b = ", b);
	scanf("%d" , &b);
	if(a==0 || b==0){
		return a + b;
		}
	while(a*b != 0){
		if(a>b){
			a -= b;
			}
		else{
			b -= a; 
			} 
	printf("UCLL = %d", a);
	return a ;}
	
	}
	
