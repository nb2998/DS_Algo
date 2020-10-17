package DP.Dp_practice;

import java.util.Scanner;

// Count Possible Decodings of a given Digit Sequence
// Let 1 represent ‘A’, 2 represents ‘B’, etc. Given a digit sequence, count the number of possible decodings of the given digit sequence.
// Examples:

// Input:  digits[] = "121"
// Output: 3
// // The possible decodings are "ABA", "AU", "LA"

// Input: digits[] = "1234"
// Output: 3
// // The possible decodings are "ABCD", "LCD", "AWD"
// An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and there are no leading 0’s, no extra trailing 0’s and no two or more consecutive 0’s.

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
