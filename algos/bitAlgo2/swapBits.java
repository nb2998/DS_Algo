package bitAlgorithms;

import java.util.Scanner;

//java program which is used to swap bits in a number

public class swapBits {
	//x is a number,p1 and p2 is position, n is to swap n bits
	static int swapBit(int x, int p1, int p2, int n) 
    { 
        // Move all bits of first set 
        // to rightmost side  
        int set1 = (x >> p1) & ((1 << n) - 1); 
      
        // Move all bits of second set  
        //to rightmost side  
        int set2 = (x >> p2) & ((1 << n) - 1); 
      
        // XOR the two sets  
        int xor = (set1 ^ set2); 
      
        // Put the xor bits back to  
        // their original positions  
        xor = (xor << p1) | (xor << p2); 
      
        // XOR the 'xor' with the original number  
        // so that the  two sets are swapped  
        int result = x ^ xor; 
      
        return result; 
    } 
      
    public static void main(String[] args) 
    { 
    	Scanner sc = new Scanner(System.in);
    	System.out.println("Enter the value of x");
    	int x = sc.nextInt();
    	System.out.println("Enter the value of p1");
    	int p1 = sc.nextInt();
    	System.out.println("Enter the value of p2");
    	int p2 = sc.nextInt();
    	System.out.println("Enter the value of n");
    	int n = sc.nextInt();
    	int res = swapBit(x, p1, p2, n); 
        System.out.println("Result = " + res); 
        sc.close();
    } 
}
