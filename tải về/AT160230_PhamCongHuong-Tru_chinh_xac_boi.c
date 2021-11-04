#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

int find_mod(int a[50], int b[50], int w, int t, int n){
	int i, j;
	int check = 0;
	for(i=1;i<=t;i++){
		int mod = pow(2,w*i);
		for(j=0;j<n;j++){
			if(((a[j]>=0)&&(a[j]<=mod))&&((b[j]>=0)&&(b[j]<=mod))){
				check = i;
			}else{
				check = i+1;
			}
		}
		if(check==i){
			break;
		}
	}	
	int z = pow(2,w*check);
	return z;
}

int multiprecision_Subtraction(int a[50], int b[50], int c[50], int w, int t, int n){
	int i;
	int z = 0;
	int mod = find_mod(a,b,w,t,n);
	for( i = 0; i < n; i++){
		c[i]  = (a[i] - b[i] - z)%mod;
		if(c[i]<0){
			c[i] = c[i] + mod;
			z = 1;
		}else{
			z = 0;
		}
	}
	return z;
}

void nhap_mang(int a[50], int n){
	int i;
	for ( i=0; i<n; i++){
		printf("\nnhap phan tu %d: ", i);
		scanf("%d", &a[i]);
	}
}

void xuat_mang(int a[50], int n){
	int i;
	for ( i=n-1; i>=0; i--){
		printf("%d ", a[i]);
	}
}

int main(){
	int a[50], b[50], c[50];
	int w, t, n;
	printf("\nnhap so phan tu cua a va b: ");
	scanf("%d", &n);
	printf("\nnhap w va t lan luot: ");
	scanf("%d%d",&w, &t);
	printf("\nnhap mang a: ");
	nhap_mang(a, n);
	printf("\nnhap mang b: ");
	nhap_mang(b, n);
	int z = multiprecision_Subtraction(a,b,c,w,t,n);
	printf("\nKETQUA: %d, ", z);
	xuat_mang(c,n);
	return 0;
}
