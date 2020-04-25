/*For more detail visit the link https://practice.geeksforgeeks.org/problems/series-gp/0*/
#include<stdio.h>
#include<math.h>
int main(){

	int f,s,term;
	scanf("%d %d %d",&f,&s,&term);
	
	int ratio=s/f;
	
	printf("%f",(f*(pow(ratio,term-1))));
}
