/*Kth smallest element in an array*/
#include<stdio.h>
#include<stdlib.h>
int compare(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}
int main(){
	int a[]={3,2,1,4,5,6};
	int n=6;
	int k=3;  //kth smallest element which we have to find
	qsort(a,6,sizeof(a[0]),compare);
	if(k>n||k<=0){
		printf("-1 does not exist");
	}
	
	printf("%d",a[n-k]);
}
