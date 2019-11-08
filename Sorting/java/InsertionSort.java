import java.io.*;
import java.util.*;
import java.util.Scanner;

public class InsertionSort 
{ 

  public static void Sort(int A[]) 
  { 
      for(int i=1;i<A.length;i++){

          int temp = A[i];
          int j = i-1;

          whiel(j>=0 && A[j]>temp){
             A[j+1] = A[j];
             j= j-1;

         }
            A[j+1] = temp;

      }
  } 

   public static void main(String args[]) { 
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int[] A =new int[N];
        for(int i =0;i<N;i++){
          A[i] = sc.nextInt();  
        }
	 Sort(A);
         for(int i=0;i<N;i++){ 
          System.out.print(A[i]);
         
         } 
   } 
} 
