/*For question detail go to https://practice.geeksforgeeks.org/problems/series-ap/0*/

#include<stdio.h>

int main(){
	
	int f,s;
	scanf("%d %d",&f,&s);
	
	int diff=s-f;
	
	int term;
	scanf("%d",&term);
	
	printf("%d",(s+(diff*(term-2))));
	
	return 0;
}
