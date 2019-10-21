import java.util.Scanner;

//Question is of codechef megacook off october
// You are playing EVE Online. Initially, you have one dollar, but you have somehow acquired two cheat codes.
//The first cheat code multiplies the amount of money you own by 10, while the second one multiplies it by 20. 
//The cheat codes can be used any number of times.You want to have exactly N dollars.
//Now you are wondering: can you achieve that by only using some sequence of cheat codes?
public class cakewalk {
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0){
		    long n = sc.nextLong();
		    long temp = n;
		    long p = n%10;
		    long c = 0l;
		    while(p==0){
		        c++;
		        temp = temp/10;
		        p = temp%10;
		    }
		    double res = Math.log(temp)/Math.log(2.0);
		    if(res == (int)res && c>=res)
		    System.out.println("Yes");
		    else
		    System.out.println("No");
		    t--;
		}
	}
}
