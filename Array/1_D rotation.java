/*For Questoin detail go to https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0*/

import java.util.*;

class Main{
	public static void main(String args[]){
	
	int a[]={1,2,3,4,5,6}; //initial array
	
	int r=2; //no of rotation
	int n=a.length;
	r=r%n;
	for(int i=0;i<r;i++){
		int temp=a[0];
		for(int j=0;j<n-1;j++){
		a[j]=a[j+1];
		}
		a[n-1]=temp;
	}
	for(int i=0;i<n;i++)
		System.out.println(a[i]+" ");
	
	}
}
