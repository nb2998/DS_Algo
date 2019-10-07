import java.io.*;
import java.util.*;
import java.util.Scanner;

public class SelectionSort 
{ 
  public static void Sort(int A[]) 
  { 
        int temp,min;
	for(int i=0; i<A.length-1; i++) 
	{  
              min = i;
	    for(int j =i+1;j<A.length;j++){
                if(A[j]<A[min]){
                    min = j;
                }
              temp = A[min];
              A[min] = A[i];
              A[i] = temp;
            }
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
