#include<stdio.h>

void swap(int *n,int *m){

	int temp=*n;
	*n=*m;
	*m=temp;
	
}

void heapify(int arr[],int n,int i){
	int largest=i,left=2*i+1,right=2*i+2;
	if(left<n && arr[left] > arr[largest])
		largest=left;
	
	if(right < n && arr[right] > arr[largest])
		largest=right;
	if(largest!=i){
		swap(arr+i,arr+largest);
		heapify(arr,n,largest);
	}
}

void heapsort(int arr[],int n){
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
		for(int i=n-1;i>=0;i--)
	{
		swap(arr+0,arr+i);
		heapify(arr,i,0);
	}
}
int main(){
	int arr[]={1,2,3,4,5,6,7};
	
	int n=7;
	heapsort(arr,n);
	for(int i=0;i<n;i++)
		printf("%d",arr[i]);
	return 0;
}
