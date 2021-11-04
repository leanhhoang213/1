#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

long GCD(long a, long b){
	int r;
	while(b>0){
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

long pollard_Rho(long n){
	long a, b, d, z;
	a = 2;
	b = 2;
	while(1){
		a = (a*a+1)%n;
		b = (b*b+1)%n;
		b = (b*b+1)%n;
		if((a-b)<0){
			z = b-a;
		}else{
			z = a-b;
		}
		d = GCD(z,n);
		if(d>1&&d<n){
			printf("thanh cong!\n");
			break;
		}
		if(d==n){
			printf("\nthat bai!\n");
			break;
		}	
	}
	return d;
}

int main(){
	long n, d;
	printf("nhap n:");
	scanf("%ld", &n);
	d = pollard_Rho(n);
	printf("ket qua: %ld", d);
	return 0;
}
