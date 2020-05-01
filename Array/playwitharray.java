/*Element at odd index must be greater than element at even index
https://practice.geeksforgeeks.org/problems/play-with-an-array/1
*/
import java.util.*;
class Main{

	public static void main(String args[]){
	
		int a[]={6,5,2,3,4,4};
		int n=a.length,flag=0,temp;
		Arrays.sort(a);
		if(n<=1){
			System.out.println(0);
		}
		for(int i=0;i<n/2;i++)
		{
			temp=a[i];
			a[i]=a[n-i-1];
			a[n-i-1]=temp;
		}
		for(int i=0;i<n;i=i+2){
			if(i+1<n){
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
		
		for(int i=0;i<n;i=i+2)
		{
			if(a[i]<a[i+1]){
				continue;
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			System.out.println('0');
		else
			System.out.println(1);
	}
}
