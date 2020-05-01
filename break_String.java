import java.util.*;

class Main{
	public static void main(String argsp[]){
		Scanner scan = new Scanner(System.in);
		String str=scan.nextLine();
		
		int i,nextLineFlag=0,quotesFlag=0;
		for(i=0;i<str.length();i++){
			if(str.charAt(i)!='!' && str.charAt(i)!='.' && str.charAt(i)!='?'){
				if(nextLineFlag==1 && str.charAt(i)==' ')
				{
					nextLineFlag=0;
				}
				else {
				System.out.print(str.charAt(i));
				}
				if(str.charAt(i) == '"'){
					quotesFlag=quotesFlag==1?0:1;
				}
			}
			else if((str.charAt(i)=='.' || str.charAt(i)=='!' || str.charAt(i)=='?') && quotesFlag == 0)
			{
				System.out.println(str.charAt(i));
				nextLineFlag=1;
			}
			else{
			
			}
			
		}
	}
}
