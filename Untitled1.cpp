 #include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rounds(double x)
{
    int iX = (int) x;
    if(x-iX>0)
    {
        return iX+1;
    }
    else
    {
        return iX;
    }
}

long* digitToArray(unsigned long x,int w, int t)
{
    long* a;
    int i;
    a = (long*)malloc(t * sizeof(long));
    for(i = t-1; i>=0; --i)
    {
        a[t-i-1]=x/pow(2,w*i);
        x%=(int)pow(2,w*i);
    }
    return a;
}

void printArr(long a[],int size)
{
	int i;
    for(i =0; i<size; ++i)
    {
        printf("%lu  ",a[i]);
    }
    printf("\n");
}

int sizeOfArr(unsigned long p,int w)
{
    int m = rounds(log(p)/log(2)) ;
    return m%w ? m/w + 1 : m/w;
}

int main(){
	unsigned long a,p;
	int w,t;
	printf("Nhap a, p, w: ");
	scanf("%lu%lu%d",&a,&p,&w);
	
	t = sizeOfArr(p,w);
	long *arrA = digitToArray(a,w,t);
	
	printArr(arrA,t);
}

