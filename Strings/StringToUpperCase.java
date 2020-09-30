//Convert a string totally into upper case?

import java.util.Scanner;
public class StringToUpperCase {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = str1.toUpperCase();
        System.out.println("Original String: "+str1);
        System.out.println("String changed to upper case: "+str2);
    }
}


