package Lec3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;

public class Recursion2 {

	public static ArrayList<String> coinToss(int n) {

		if (n == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}

		ArrayList<String> recRes = coinToss(n - 1);

		ArrayList<String> myRes = new ArrayList<>();
		for (String rs : recRes) {
			myRes.add("H" + rs);
			myRes.add(rs + "T");
		}
		return myRes;
	}

	public static ArrayList<String> mazePath(int cr, int cc, int r, int c) {

		if (cr == r && cc == c) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}
		if (cr > r || cc > c) {
			return new ArrayList<String>();
		}

		ArrayList<String> recRes = mazePath(cr + 1, cc, r, c);
		ArrayList<String> recRes1 = mazePath(cr, cc + 1, r, c);
		ArrayList<String> myRes = new ArrayList<>();
		for (String rs : recRes) {
			myRes.add("H" + rs);
		}
		for (String rs : recRes1) {
			myRes.add("V" + rs);
		}
		return myRes;

	}

	// this method is wrong as it prints all the permutations too
	static ArrayList<String> denom(int[] arr, int total) {
		if (total == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}
		if (total < 0) {
			return new ArrayList<String>();
		}

		ArrayList<String> myRes = new ArrayList<>();

		for (int i = 0; i < arr.length; i++) {
			ArrayList<String> recRes = denom(arr, total - arr[i]);
			for (String rs : recRes) {
				myRes.add(arr[i] + rs);
			}
		}
		return myRes;

		// permutations occurring
	}

	// no permutation
	static ArrayList<String> denom2(int[] arr, int s, int total) {
		if (total == 0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}
		if (total < 0 || s > arr.length - 1) {
			return new ArrayList<String>();
		}
		ArrayList<String> myRes = new ArrayList<>();
		ArrayList<String> recResWithi = denom2(arr, s, total - arr[s]);
		ArrayList<String> recResWithouti = denom2(arr, s + 1, total);
		for (String rs : recResWithi) {
			myRes.add(rs + arr[s]);
		}

		for (String rs : recResWithouti) {
			myRes.add(rs);
		}
		return myRes;
	}

	// TODO in O(n) and O(k)
	static ArrayList<Integer> subArray(int[] arr, int k) {
		ArrayList<Integer> al = new ArrayList<>();
		int i = 0, j = k;

		return al;
	}

	static void printSS(String ques, String ans) {

		if (ques.length() == 0) {
			System.out.print(ans + " ");
			return;
		}

		char ch = ques.charAt(0);
		String roq = ques.substring(1);

		printSS(roq, ans);
		printSS(roq, ans + ch);
	}

	static String getCharsOfKeypad(char digit) {
		switch (digit) {
		case '1':
			return "abc";
		case '2':
			return "def";
		case '3':
			return "ghi";
		case '4':
			return "jk";
		case '5':
			return "lmno";
		case '6':
			return "pqrs";
		case '7':
			return "tu";
		case '8':
			return "vw";
		case '9':
			return "xyz";
		case '0':
			return "#$";
		default:
			return "";
		}

	}

	static void printkpc(String ques, String ans) {

		if (ques.length() == 0) {
			System.out.print(ans + " ");
			return;
		}

		char ch = ques.charAt(0);
		String roq = ques.substring(1);

		String charsKP = getCharsOfKeypad(ch);
		for (int i = 0; i < charsKP.length(); i++) {
			printkpc(roq, ans + charsKP.charAt(i));
		}

	}

	static void printPermutation(String ques, String ans) {
		if (ques.length() == 0) {
			System.out.print(ans + " ");
			return;
		}
		char ch = ques.charAt(0);
		String roq = ques.substring(1);
		for (int j = 0; j <= ans.length(); j++) {
			printPermutation(roq, ans.substring(0, j) + ch + ans.substring(j));
		}

	}

	static void printPermBtr(String ques, String ans) {
		if (ques.length() == 0) {
			System.out.print(ans + " ");
			return;
		}

		for (int i = 0; i < ques.length(); i++) {
			char ch = ques.charAt(i);
			String roq = ques.substring(0, i) + ques.substring(i + 1);
			printPermBtr(roq, ans + ch);
		}
	}

	static void printCoinToss(int n, String ans) {

		if (n == 0) {
			System.out.print(ans + " ");
			return;
		}

		printCoinToss(n - 1, "H" + ans);
		printCoinToss(n - 1, ans + "T");

	}

	static void printMazePath(int cr, int cc, int r, int c, String ans) {
		if (cr == r && cc == c) {
			System.out.print(ans + " ");
			return;
		}
		if (cr > r || cc > c)
			return;
		printMazePath(cr, cc + 1, r, c, ans + "H");
		printMazePath(cr + 1, cc, r, c, ans + "V");
	}

	static void printBoardPath(int ci, int fi, String ans) {
		if (ci == fi) {
			System.out.print(ans + " ");
			return;
		}
		if (ci > fi)
			return;
		for (int i = 1; i <= 6; i++) {
			printBoardPath(ci + i, fi, ans + i);
		}
	}

	public static int permutationRemoveDuplicates(String ques, String ans) {
		if (ques.length() == 0) {
			System.out.print(ans + " ");
			return 1;
		}
		int count = 0;

		HashSet<Character> hs = new HashSet<>();
		for (int i = 0; i < ques.length(); i++) {
			char ch = ques.charAt(i);
			if (!hs.contains(ch)) {
				hs.add(ch);
				String roq = ques.substring(0, i) + ques.substring(i + 1);
				count += permutationRemoveDuplicates(roq, ans + ch);
			}
		}
		return count;
	}

	// TODO
	public static int PermutationLexicoLarger(String ques, String ans) {
		if (ques.length() == 0) {
			System.out.print(ans + " ");
			return 1;
		}
		int count = 0;

		HashSet<Character> hs = new HashSet<>();
		// ArrayList<Character> chars = new ArrayList<>();
		// for(int i=0; i<ques.length(); i++) chars.add(ques.charAt(i));
		// System.out.println(chars);
		// Collections.sort(chars, new Comparator<Character>() {
		// @Override
		// public int compare(Character o1, Character o2) {
		// System.out.println("compare"+((int)o1>(int)o2));
		// if((int)o1>(int)o2) return 1;
		// else if((int)o1<(int)o2) return -1;
		// else return 0;
		// }
		// });
		// System.out.println(chars);
		for (int i = 0; i < ques.length(); i++) {
			char ch = ques.charAt(i);
			if (!hs.contains(ch)) {
				hs.add(ch);
				String roq = ques.substring(0, i) + ques.substring(i + 1);
				if (!ans.equals("")) {
					System.out.println(ch < ans.charAt(ans.length() - 1));
					if (ch < ans.charAt(ans.length() - 1))
						count += permutationRemoveDuplicates(roq, ans + ch);
					else
						count += permutationRemoveDuplicates(roq, ch + ans);
				} else
					count += permutationRemoveDuplicates(roq, ans + ch);
			}
		}
		return count;
	}

	public static void LexicoGraphicallyCounting(int curr, int end) {
		if (curr == 0) {
			System.out.print(curr + " ");
			return;
		}
		if (curr <= end) {
			System.out.print(curr + " ");
		}
		if (curr > end)
			return;

		for (int i = 0; i <= 9; i++) {
			if ((curr * 10 + i) <= end)
				LexicoGraphicallyCounting(curr * 10 + i, end);

		}

		if (curr + 1 <= 9)
			LexicoGraphicallyCounting(curr + 1, end);

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(coinToss(3));
		System.out.println(mazePath(0, 0, 3, 3));
		int[] arr = { 1, 2, 5 };
		System.out.println("*****");
		System.out.println(denom2(arr, 0, 10));
		printSS("abc", "");
		System.out.println();
		printkpc("145", "");
		// System.out.println();
		// printPermutation("abc", "");
		// System.out.println();
		// printCoinToss(3, "");
		// System.out.println();
		// printMazePath(0, 0, 3, 3, "");
		// System.out.println();
		// printBoardPath(0, 7, "");
		// System.out.println();
		// printPermBtr("abc", "");
		System.out.println();
		System.out.println(permutationRemoveDuplicates("abca", ""));
		System.out.println(PermutationLexicoLarger("cbca", ""));
		LexicoGraphicallyCounting(1, 1000);
	}

}
