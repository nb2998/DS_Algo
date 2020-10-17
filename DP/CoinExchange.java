//~ //The following program illustrates optimised DP approach to solve
//~ the following problem.
//~ Given k coins, find the number of ways to pay n amount.

import java.util.*;

public class CoinChange_Modified{
	private static Scanner sc;
	private static int amount;
	private static int[] coins;
	
	public static void main(String[] args){
		sc = new Scanner(System.in);
		amount = sc.nextInt();
		int N = sc.nextInt();
		
		coins = new int[N];
		for(int i = 0; i < N; i++)
			coins[i] = sc.nextInt();
		
		System.out.println(minimumCoinsNeeded(amount, coins));
		
	}	
	
	private static int minimumCoinsNeeded(int amount, int[] coins){
		int[] table = new int[amount+1];
		//Initialising the table.
		for(int i = 0; i <= amount; i++)
			table[i] = 1;
		
		for(int j = 1; j < coins.length; j++){
			for(int currentAmt = 0; currentAmt <= amount; currentAmt++){
				if(coins[j] <= currentAmt)
						table[currentAmt] = table[currentAmt] + table[currentAmt - coins[j]];
			}
		}
		return table[amount];
	}	
}
