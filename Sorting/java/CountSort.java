import java.io.*;
import java.util.*;
import java.util.Scanner;

public class CountSort 
{ 

   static void Sort(int A[]) 
  { 
     int n = A.length;
     int k= n+1;   
     int AUX[] = new int[k];  
     int count[] = new int[n]; 
        for (int i=0; i<k; ++i) 
             AUX[i] = 0; 
  
        for (int i=0; i<n; ++i) 
            ++AUX[A[i]]; 
  
        for (int i=1; i<=k; ++i) 
            AUX[i] += AUX[i-1]; 
  
        for (int i =n-1; i>=0; i--) 
        { 
            count[AUX[A[i]]-1] = A[i]; 
            --AUX[A[i]]; 
        } 
  
        for (int i = 0; i<n; ++i) 
            A[i] = count[i]; 

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
