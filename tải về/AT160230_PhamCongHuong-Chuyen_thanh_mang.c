#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

void bieu_dien_duoi_dang_mang(int a, int b[50], int w, int p){
	int i;
	int m = (log(p)/log(2)) + 1;
	int t = (m/w) + 1;
	for(i = t-1; i >= 0; i--){
		int z = pow(2,w*i);
		b[i] = (a-a%z)/z;
		a = a%z;
	}
	for(i = t-1; i >= 0; i--){
		printf("%d, ", b[i]);
	}
}

int main(){
	int b[50];
	int a, w, p;
	printf("\n nhap a: ");
	scanf("%d", &a);
	printf("\n nhap w: ");
	scanf("%d", &w);
	printf("\n nhap p: ");
	scanf("%d", &p);
	printf("\n ket qua: ");
	bieu_dien_duoi_dang_mang(a,b,w,p);
	return 0;
}
