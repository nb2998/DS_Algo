package DP.Dp_practice;

import java.util.Scanner;

public class DecodeIntString {

    public static int numDecodings(String s) {
        char[] ar = new char[s.length()];
        for (int i = 0; i < s.length(); i++) {
            ar[i] = s.charAt(i);
        }
        return numDecodingsPrivate(ar, s.length(), new int[s.length() + 1]);
    }

    public static int numDecodingsPrivate(char[] as, int k, int[] qs) {
        if (k == 0) 
            return 1;
        int s = as.length - k;

        if (as[s] == '0') 
            return 0;

        if (qs[k] != 0) 
            return qs[k];

        int result = nn(as, k - 1, qs);

        if (k >= 2) {
            if (as[s] == '1' || (as[s] <= '2') && (as[s + 1] < '7')){
                result += nn(as, k - 2, qs);
            }
        }

        qs[k] = result;
        return result;
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        String a = s.next();
        System.out.println(numDecodings(a));
    }
}
