package bitAlgorithms;

import java.util.Scanner;

//this program is used to check if 
// two numbers have opposite sign using bit manipulations
public class detectOppositeSigns {
	
	static boolean oppositeSigns(int x, int y) 
    { 
        return ((x ^ y) < 0); 
    } 
      
    public static void main(String[] args) 
    { 
    	Scanner sc = new Scanner(System.in);
    	int x = sc.nextInt();
    	int y = sc.nextInt(); 
        if (oppositeSigns(x, y) == true) 
            System.out.println("Signs are opposite"); 
        else
            System.out.println("Signs are not opposite"); 
        sc.close();
    } 
}
