package Lec2;

import java.util.ArrayList;;

public class RecusrionAL {

	static ArrayList<String> subSeqWithAscii(String s) {

		if (s.length() == 0) {
			ArrayList<String> baseRes = new ArrayList<>();
			baseRes.add("");
			return baseRes;
		}

		char ch = s.charAt(0);
		String ros = s.substring(1);

		ArrayList<String> recRes = subSeqWithAscii(ros);

		ArrayList<String> myRes = new ArrayList<>();
		for (String rs : recRes) {
//			System.out.println();
			myRes.add(rs);
			myRes.add(ch + rs);
			myRes.add((int) ch + rs);
		}
		return myRes;

	}

	static String getCharsOfKeypad(int digit) {
		switch (digit) {
		case 1:
			return "abc";
		case 2:
			return "def";
		case 3:
			return "ghi";
		case 4:
			return "jk";
		case 5:
			return "lmno";
		case 6:
			return "pqrs";
		case 7:
			return "tu";
		case 8:
			return "vw";
		case 9:
			return "xyz";
		case 0:
			return "#$";
		default:
			return "";

		}
	}

	static ArrayList<String> keypad(int num) {

		if (num <= 0) {
			ArrayList<String> baseRes = new ArrayList<>();
			baseRes.add("");
			return baseRes;
		}

		String s = getCharsOfKeypad(num % 10);

		ArrayList<String> recRes = keypad(num / 10);

		ArrayList<String> myRes = new ArrayList<>();
		for (int j = 0; j < s.length(); j++) {
			for (String rs : recRes) {
				myRes.add(s.charAt(j) + rs);
			}
		}

		return myRes;

	}

	static ArrayList<String> permutations(String s){
		
		if(s.length()==0) {
			ArrayList<String> baseRes=new ArrayList<>();
			baseRes.add("");
			return baseRes;
		}
		 
		 char ch= s.charAt(0);
		 String ros=s.substring(1);
		 ArrayList<String> recRes= permutations(ros);
		 
		 ArrayList<String> myRes=new ArrayList<>();
		 for(String rs:recRes) {
//			 System.out.println(recRes.size());
			 for(int j=0; j<=rs.length(); j++) {
				 myRes.add(rs.substring(0, j) + ch + rs.substring(j));
//				 System.out.println(myRes.size());
			 }
		 }
		 return myRes;
	 }
	
//	static ArrayList<String> boardPath(int num){
//		
//		if(num==1 || num==2 || num==3|| num==4||num==5||num==6) {
//			ArrayList<String> br = new ArrayList<>();
//			br.add((num!=1)?""+(num-1):"");
//			return br;
//		}
//		ArrayList<ArrayList<String>> recRes=new ArrayList<ArrayList<String>>();
//		for(int i=1; i<=6; i++) {
//			recRes.add(boardPath(num-i));
//		}
//		
//		ArrayList<String> myRes = new ArrayList<>();
//		for(int i=1; i<=6; i++) {
//			for(String rs: recRes.get(i)) {
//				myRes.add(rs+i);
//			}
//		}
//		return myRes;
//	}
	
	static ArrayList<String> boardPath1(int num){
		if(num<=0) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}
		ArrayList<String> recRes = boardPath1(num-1);
		
		ArrayList<String> myRes = new ArrayList<>();
		for(int i=1; i<=6; i++) {
			for(String rs: recRes) {
				myRes.add(rs+i);
			}
		}
		return myRes;
	}
	
	static ArrayList<String> boardPath(int ci, int fi){
		if(ci==fi) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}
		if(ci>fi) {
			ArrayList<String> br = new ArrayList<>();
			return br;
		}
		ArrayList<String> recRes1 = boardPath(ci+1, fi);
		ArrayList<String> recRes2 = boardPath(ci+2, fi);
		ArrayList<String> recRes3 = boardPath(ci+3, fi);
		ArrayList<String> recRes4 = boardPath(ci+4, fi);
		ArrayList<String> recRes5 = boardPath(ci+5, fi);
		ArrayList<String> recRes6 = boardPath(ci+6, fi);
		ArrayList<String> myRes = new ArrayList<>();
//		ArrayList<String> recRes;
		for(String rs:recRes1) {
			myRes.add(rs+"1");
		}
		for(String rs:recRes2) {
			myRes.add(rs+"2");
		}
		for(String rs:recRes3) {
			myRes.add(rs+"3");
		}
		for(String rs:recRes4) {
			myRes.add(rs+"4");
		}
		for(String rs:recRes5) {
			myRes.add(rs+"5");
		}
		for(String rs:recRes6) {
			myRes.add(rs+"6");
		}
		return myRes;
	}
	
	static ArrayList<String> getBoardPath(int ci, int fi){
		if(ci==fi) {
			ArrayList<String> br = new ArrayList<>();
			br.add("");
			return br;
		}
		ArrayList<String> myRes=new ArrayList<>();
		for(int dice=1; dice<=6 && ci+dice<=fi; dice++) {
			ArrayList<String> recRes=getBoardPath(ci+dice, fi);
			
			for(String rs: recRes) {
				myRes.add(dice+rs);
			}
		}
		return myRes;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		System.out.println(subSeqWithAscii("ab"));
		System.out.println(keypad(145));
//		System.out.println(permutations("abc"));
		System.out.println(getBoardPath(0, 10).size());
	}

}
