package Lec12;

public class DPContd {

	static int editDist(String s1, String s2) {

		if (s1.length() == 0 || s2.length() == 0)
			return Math.max(s1.length(), s2.length());

		char ch1 = s1.charAt(0);
		char ch2 = s2.charAt(0);
		String ros1 = s1.substring(1);
		String ros2 = s2.substring(1);

		int ans = 0;
		if (ch1 == ch2) {
			ans = editDist(ros1, ros2);
		} else {
			int one = editDist(ros1, s2);
			int two = editDist(s1, ros2);
			int three = editDist(ros1, ros2); // replace
			ans = Math.min(one, Math.min(two, three)) + 1;
		}

		return ans;
	}

	static int editDistTD(String s1, String s2, int[][] strg) {

		if (s1.length() == 0 || s2.length() == 0)
			return Math.max(s1.length(), s2.length());

		if (strg[s1.length()][s2.length()] != 0)
			return strg[s1.length()][s2.length()];

		char ch1 = s1.charAt(0);
		char ch2 = s2.charAt(0);
		String ros1 = s1.substring(1);
		String ros2 = s2.substring(1);

		int ans = 0;
		if (ch1 == ch2) {
			ans = editDistTD(ros1, ros2, strg);
		} else {
			int one = editDistTD(ros1, s2, strg);
			int two = editDistTD(s1, ros2, strg);
			int three = editDistTD(ros1, ros2, strg); // replace
			ans = Math.min(one, Math.min(two, three)) + 1;
		}

		strg[s1.length()][s2.length()] = ans;
		return ans;
	}

	static int editDistBU(String s1, String s2) {
		int[][] strg = new int[s1.length() + 1][s2.length() + 1];

		for (int i = s1.length(); i >= 0; i--) {
			for (int j = s2.length(); j >= 0; j--) {
				if (i == s1.length() && j == s2.length())
					strg[i][j] = 0;
				else if (i == s1.length())
					strg[i][j] = s2.length() - j;
				else if (j == s2.length())
					strg[i][j] = s1.length() - i;
				else {
					if (s1.charAt(i) == s2.charAt(j))
						strg[i][j] = strg[i + 1][j + 1];
					else {
						int one = strg[i][j + 1];
						int two = strg[i + 1][j];
						int three = strg[i + 1][j + 1];
						strg[i][j] = Math.min(one, Math.min(two, three)) + 1;
					}

				}
			}
		}

		return strg[0][0];

	}

	static int MCMTD(int[] arr, int si, int ei, int[][] strg) {
		if (si == ei - 1)
			return 0;
		if (strg[si][ei] != 0)
			return strg[si][ei];

		int min = Integer.MAX_VALUE;
		for (int k = si + 1; k < ei; k++) {
			int fp = MCMTD(arr, si, k, strg);
			int sp = MCMTD(arr, k, ei, strg);
			int sw = arr[si] * arr[k] * arr[ei];

			int sum = fp + sp + sw;
			if (sum < min)
				min = sum;
		}
		strg[si][ei] = min;
		return min;
	}

	static int MCMBU1(int[] arr) {
		int[][] strg = new int[arr.length][arr.length];

		for (int i = arr.length - 3; i >= 0; i--) {
			for (int j = i + 2; j < arr.length; j++) {
				int min = Integer.MAX_VALUE;
				for (int k = i + 1; k <= j - 1; k++) {
					int fp = strg[i][k];
					int sp = strg[k][j];
					int sw = arr[i] * arr[k] * arr[j];
					int sum = fp + sp + sw;
					if (sum < min)
						min = sum;
				}
				strg[i][j] = min;
			}
		}

		return strg[0][arr.length - 1];
	}

	static int MCMBU(int[] arr) {
		int n = arr.length;
		int[][] strg = new int[n][n];

		for (int slide = 1; slide <= n - 2; slide++) {
			for (int si = 0; si <= n - slide - 2; si++) {
				int min = Integer.MAX_VALUE;
				int ei = si + slide + 1;
				for (int k = si + 1; k <= ei - 1; k++) {
					int fp = strg[si][k];
					int sp = strg[k][ei];
					int sw = arr[si] * arr[k] * arr[ei];
					int sum = fp + sp + sw;
					if (sum < min)
						min = sum;
				}

				strg[si][ei] = min;
			}
		}
		return strg[0][n - 1];

	}

	static int WineProblem(int[] prices, int si, int ei) {
		int yr = prices.length - (ei - si);
		if (si == ei)
			return prices[si] * yr;

		int fp = WineProblem(prices, si + 1, ei) + (prices[si] * yr);
		int sp = WineProblem(prices, si, ei - 1) + (prices[ei] * yr);

		int ans = Math.max(fp, sp);
		return ans;
	}

	static int WineProblemTD(int[] prices, int si, int ei, int[][] strg) {
		int yr = prices.length - (ei - si);
		if (si == ei)
			return prices[si] * yr;
		if (strg[si][ei] != 0)
			return strg[si][ei];

		int fp = WineProblemTD(prices, si + 1, ei, strg) + (prices[si] * yr);
		int sp = WineProblemTD(prices, si, ei - 1, strg) + (prices[ei] * yr);

		int ans = Math.max(fp, sp);
		strg[si][ei] = ans;
		return ans;
	}

	static int WineProblemBU(int[] prices) {
		int n = prices.length;
		int[][] strg = new int[prices.length][prices.length];

		for (int slide = 1; slide <= n; slide++) {
			for (int si = 0; si <= n - slide; si++) {

				int ei = si + slide - 1;

				int yr = prices.length - (ei - si);
				if (si == ei)
					strg[si][ei] = prices[si] * yr;
				else {
					int fp = strg[si + 1][ei] + (prices[si] * yr);
					int sp = strg[si][ei - 1] + (prices[ei] * yr);

					int ans = Math.max(fp, sp);
					strg[si][ei] = ans;
				}
			}
		}

		return strg[0][prices.length - 1];
	}

	// TODO
	static int minJumps(int[] arr, int curr, int[] strg) {
		if (curr == arr.length - 1)
			return 1;
		if (curr > arr.length - 1)
			return 0;
		if (arr[curr] == 0)
			return 0;
		if(arr[curr]+curr>=arr.length-1) 
			return 1;
		if(strg[curr]!=0) return strg[curr];
		
		int max = curr + 1;
		for (int i = 1; i <= arr[curr]; i++) {
			if(curr+i<arr.length && arr[curr+i]>max) {
				max=curr+i;
			}
		}

		int ans= minJumps(arr, max, strg)+1;
		strg[curr] = ans;
		return ans;

	}

//	static int minJumpsBU(int[] arr) {
//		int[] str
//	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		String s1 = "abcd";
//		String s2 = "agcfd";
//		System.out.println(editDist("abcd", "agcfd"));
//		System.out.println(editDistTD(s1, s2, new int[s1.length() + 1][s2.length() + 1]));
//		System.out.println(editDistBU(s1, s2));
//
//		int[] arr = { 1, 2, 3, 4 };
//		System.out.println(MCMTD(arr, 0, arr.length - 1, new int[arr.length][arr.length]));
//		System.out.println(MCMBU(arr));
//		System.out.println(MCMBU1(arr));
//		int[] prices = { 2, 3, 5, 1, 4 };
//		System.out.println(WineProblem(prices, 0, prices.length - 1));
//		System.out.println(WineProblemTD(prices, 0, prices.length - 1, new int[prices.length][prices.length]));
//		System.out.println(WineProblemBU(prices));
		int[] arr = {1,3,5,8,9,2,6,7,6,8,9};
		System.out.println(minJumps(arr, 0, new int[arr.length]));
	}

}
