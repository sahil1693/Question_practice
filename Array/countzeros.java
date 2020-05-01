/*Find all pair such that A[i] XOR A[j] is 0
https://practice.geeksforgeeks.org/problems/counts-zeros-xor-pairs/0

*/
import java.util.*;
class Main{

	public static void main(String args[]){
	
	int a[]={2,2,2};
	int n=a.length;
	
	Arrays.sort(a);
	int count=0;
	int temp=0;
	for(int i=0;i<n-1;i++){
	
		if(a[i]==a[i+1])
			temp++;
		else{
			if(temp!=0)
			{
				count+=((temp*(temp+1))/2);
			}
			temp=0;
		}
	}
	if(temp!=0)
			{
				count+=((temp*(temp+1))/2);
			}
	System.out.println(count);
	}
}
