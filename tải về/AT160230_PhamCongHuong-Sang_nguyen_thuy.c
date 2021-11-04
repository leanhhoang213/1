#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

void sang_nguyen_thuy(int arr[1000], int n){
	int i,j;
	for(i=0;i<=n;i++){
		arr[i] = 1;
	}
	for(i=2;i<=n;i++){
		if(arr[i]==1){
			j = 2;
			while((i*j)<=n){
				arr[i*j] = 0;
				j++;
			}
		}
	}
	for(i=2;i<=n;i++){
		if(arr[i]==1){
			printf("%d ", i);
		}
	}
}

int main(){
	int arr[1000], n;
	printf("\nnhap n: ");
	scanf("%d", &n);
	sang_nguyen_thuy(arr,n);
	return 0;
}
