import java.io.*;
import java.util.*;
import java.util.Scanner;

public class BubbleSort 
{ 
  void Sort(int A[]) 
  { 
        int temp;
	for(int i=0; i<A.length-1; i++) 
	{  
	    for(int j =0;j<A.length-i-1;j++){
                if(A[j]>A[j+1]){
                  temp = A[j+1];
                  A[j+1] = A[j];
                  A[j] = temp;
                }
            }
	} 
  } 

   public static void main(String args[]) { 
	Scanner sc = new Scanner(System.in);
        BubbleSort ob = new BubbleSort();
	int N = sc.nextInt();
	int[] A =new int[N];
   
        for(int i =0;i<N;i++){
          A[i] = sc.nextInt();  
        }
	 ob.Sort(A);
         for(int i=0;i<N;i++){ 
          System.out.print(A[i]);
         
         } 
   } 
} 
