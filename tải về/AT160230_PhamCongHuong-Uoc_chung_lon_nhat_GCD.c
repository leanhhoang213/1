#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

int GCD(int a, int b){
	int r;
	while(b>0){
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main(){
	int a, b;
	printf("nhap a va b: ");
	scanf("%d%d",&a,&b);
	printf("GCD(%d,%d)=%d",a,b,GCD(a,b));
	return 0;
}
