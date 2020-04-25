/*For Question detail go to https://practice.geeksforgeeks.org/problems/print-the-pattern-set-1/1*/


#include<stdio.h>
int main(){

	int n;
	scanf("%d",&n);
	
	for(int i=n;i>=1;i--){
	
		for(int j=n;j>=1;j--){
		
			for(int k=0;k<i;k++){
				printf("%d ",j);
			}
		}
		printf("\n");
	}
}
