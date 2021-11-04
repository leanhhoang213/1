#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

void bieu_dien_duoi_dang_mang(int f[50], int w, long p){
	int i;
	int m = (log(p)/log(2)) + 1;
	int t = (m/w) + 1;
	for(i = t-1; i >= 0; i--){
		int z = pow(2,w*i);
		f[i] = (p-p%z)/z;
		p = p%z;
	}
}

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

int multiprecision_Addition(int a[50], int b[50], int c[50], int w, int t, int n){
	int i;
	int z = 0;
	int mod = find_mod(a,b,w,t,n);
	for( i = 0; i < n; i++){
		c[i]  = (a[i] + b[i] + z)%mod;
		z = (a[i] + b[i] + z - c[i])/mod;
	}
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

int addition_in_Fp(int a[50], int b[50], int c[50], int f[50], int w, int t, int n, long p){
	int z = multiprecision_Addition(a,b,c,w,t,n);
	if(z==1){
		bieu_dien_duoi_dang_mang(f,w,p);
		z = multiprecision_Subtraction(c,f,c,w,t,n);
	}
	return z;
}

int subtraction_in_Fp(int a[50], int b[50], int c[50], int f[50], int w, int t, int n, long p){
	int z = multiprecision_Subtraction(a,b,c,w,t,n);
	if(z==1){
		bieu_dien_duoi_dang_mang(f,w,p);
		z = multiprecision_Addition(c,f,c,w,t,n);
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
	int a[50], b[50], c[50], f[50];
	int w, t, n, p;
	printf("\nnhap so phan tu cua a va b: ");
	scanf("%d", &n);
	printf("\nnhap w, t va p lan luot: ");
	scanf("%d%d%ld",&w, &t, &p);
	printf("\nnhap mang a: ");
	nhap_mang(a, n);
	printf("\nnhap mang b: ");
	nhap_mang(b, n);
	printf("\nKet qua c = a + b: ");
	int z = addition_in_Fp(a,b,c,f,w,t,n,p);
	printf("%d, ", z);
	xuat_mang(c,n);
	printf("\nKet qua c = a - b: ");
	int g = subtraction_in_Fp(a,b,c,f,w,t,n,p);
	printf("%d, ", g);
	xuat_mang(c,n);
	return 0;
}
