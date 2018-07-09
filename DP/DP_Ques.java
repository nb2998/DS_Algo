package Lec13;

public class DP_Ques {

	static int knapsack(int[] wts, int[] profit, int cap, int vi, int currPrice) {
		if (vi > wts.length - 1)
			return 0;
		if (cap == 0)
			return currPrice;
		if (cap < 0)
			return 0;

		int inc = knapsack(wts, profit, cap - wts[vi], vi + 1, currPrice + profit[vi]);
		int exc = knapsack(wts, profit, cap, vi + 1, currPrice);

		return Math.max(inc, exc);
	}

	static int knapsackTD(int[] wts, int[] profit, int cap, int vi, int currPrice, int[][] strg) {
		if (vi > wts.length - 1)
			return 0;
		if (cap == 0)
			return currPrice;
		if (cap < 0)
			return 0;

		if (strg[vi][cap] != 0)
			return strg[vi][cap];

		int inc = knapsackTD(wts, profit, cap - wts[vi], vi + 1, currPrice + profit[vi], strg);
		int exc = knapsackTD(wts, profit, cap, vi + 1, currPrice, strg);

		int ans = Math.max(inc, exc);
		strg[vi][cap] = ans;
		return ans;

	}

	static int knapsackBU(int[] wts, int[] profit, int cap) {
		int nc = cap + 1;
		int nr = wts.length + 1;
		int[][] strg = new int[nr][nc];

		for (int row = 0; row < nr; row++) {
			for (int col = 0; col < nc; col++) {
				if (row == 0 || col == 0)
					strg[row][col] = 0;
				else {
					int inc = 0;
					if (col >= wts[row - 1]) {
						inc = profit[row - 1] + strg[row - 1][col - wts[row - 1]];
					}
					int exc = strg[row - 1][col];
					strg[row][col] = Math.max(inc, exc);
				}

			}

		}

		return strg[nr - 1][nc - 1];
	}

	// static int rodCutting(int[] prices, int vi, int sumOfLen, int currPrice) {
	// if(vi>prices.length-1) return 0;
	// if(sumOfLen==prices.length) return currPrice;
	//
	// int ans=0;
	// if(sumOfLen+vi <prices.length) {
	// ans = rodCutting(prices, vi, sumOfLen+vi, currPrice+prices[vi]);
	// ans = rodCutting(prices, vi+1, sumOfLen+vi, currPrice+prices[vi]);
	// }
	//
	// }

	static int rodCutting(int[] prices, int n, int[] strg) {

		int first = 1;
		// int last=prices.length-1
		int last = n - 1;
		int max = prices[n];

		while (first <= last) {
			int f = rodCutting(prices, first, strg);
			int s = rodCutting(prices, last, strg);

			int sum = f + s;
			if (sum > max)
				max = sum;
			first++;
			last--;
		}

		return max;
	}

	static int rodCuttingBU(int[] prices) {
		int n = prices.length;
		int[] strg = new int[n + 1];
		// strg[n]=prices[n];
		for (int i = 1; i < n; i++) {
			int max = prices[i];

			int first = 1;
			int last = i - 1;
			while (first <= last) {
				int f = strg[first];
				int l = strg[last];
				int sum = f + l;
				if (sum > max)
					max = sum;

				first++;
				last--;
			}
			strg[i] = max;
		}

		return strg[n - 1];
	}

	static int color(int i, int j, int[] mix) {
		int sum = 0;
		for (int m = i; m <= j; m++)
			sum += mix[m] % 100;

		return sum % 100;
	}

	static int mixtures(int[] mix, int si, int ei) {
		if (si == ei)
			return 0;

		int min = Integer.MAX_VALUE;
		for (int k = si; k <= ei - 1; k++) {
			int one = mixtures(mix, si, k);

			int col1 = color(si, k, mix);

			int two = mixtures(mix, k + 1, ei);

			int col2 = color(k + 1, ei, mix);
			// System.out.println(col1+" "+col2);
			int smoke = col1 * col2;

			if (smoke + one + two < min)
				min = smoke + one + two;

		}
		return min;

	}

	static int mixturesBU(int[] mix) {
		int n = mix.length;
		int[][] strg = new int[mix.length][mix.length];

		for (int slide = 1; slide <= n-1; slide++) {
			for (int si = 0; si <= n - slide - 1; si++) {

				int ei = si + slide;
				
				int min = Integer.MAX_VALUE;
				for (int k = si; k <= ei - 1; k++) {
					int one = strg[si][k];
					int two = strg[k + 1][ei];
					int col1 = color(si, k, mix);
					int col2 = color(k + 1, ei, mix);
					// System.out.println(col1+" "+col2);
					int smoke = col1 * col2;

					if (smoke + one + two < min)
						min = smoke + one + two;

				}
				strg[si][ei]=min;
			}
		}

		return strg[0][n-1];
	}
	
	static boolean isPalindrome(String str, int si, int ei) {
		
		while(si<=ei) {
			if(!(str.charAt(si)==str.charAt(ei))) return false;
			
			si++;
			ei--;
		}
		return true;
	}
	
	static int palindromicPartition(String str, int si, int ei, int[][] strg) {
		if(isPalindrome(str, si, ei)){
			return 0;
		}
		
		if(strg[si][ei]!=0) return strg[si][ei];
		
		int min = Integer.MAX_VALUE;
		for(int k=si; k<=ei-1; k++) {
			int lp = palindromicPartition(str, si, k, strg);
			int rp = palindromicPartition(str, k+1, ei, strg);
			
			int ans = (rp + lp)+1;
			
			if(ans<min) min=ans;
			strg[si][ei]=min;
		}
		
		
		return min;
		
	}
	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] wts = { 1, 3, 4, 5 };
		int[] profit = { 1, 4, 5, 7 };
		int cap = 7;
		System.out.println(knapsack(wts, profit, 7, 0, 0));
		System.out.println(knapsackTD(wts, profit, cap, 0, 0, new int[wts.length + 1][cap + 1]));
		System.out.println(knapsackBU(wts, profit, cap));
		int[] prices = { 0, 1, 5, 8, 9, 10, 17, 17, 20 };
		// int[] prices = {0, 1, 3, 8, 9, 10, 17,17, 20};
		System.out.println(rodCutting(prices, prices.length - 1, new int[prices.length]));
		System.out.println(rodCuttingBU(prices));
		int[] mix = { 40, 60, 20 };
		// int[] mix= {18,19};
		System.out.println(mixtures(mix, 0, mix.length - 1));
		System.out.println(mixturesBU(mix));
		String str="ababbbabbababa";
		System.out.println(palindromicPartition(str, 0, str.length()-1, new int[str.length()][str.length()]));
	}
	

}
