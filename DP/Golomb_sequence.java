
import java.util.*; 

class GFG 
{ 
	public static int findGolomb(int n) 
	{ 
		
		// base case 
		if (n == 1) 
			return 1; 
	
		// Recursive Step 
		return 1 + findGolomb(n - 
		findGolomb(findGolomb(n - 1))); 
	} 
	
	
	
	public static void printGolomb(int n) 
	{ 
		
		for (int i = 1; i <= n; i++) 
			System.out.print(findGolomb(i) + 
									" "); 
	} 
	
	
	public static void main (String[] args) 
	{ 
		int n = 9; 
		
		printGolomb(n); 
	} 
} 


