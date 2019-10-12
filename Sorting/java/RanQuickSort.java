import java.io.*;
import java.util.*;
import java.util.Scanner;

public class RanQuickSort 

{ 
  public static int Partition(long[] A, int l, int r){
       long pivot = A[r]; 
		int i = (l-1); 
		for (int j=l; j<r; j++) {
			if (A[j] < pivot) { 
				i++;
				long temp = A[i]; 
				A[i] = A[j]; 
				A[j] = temp; 
			} 
		} 
		long temp = A[i+1]; 
		A[i+1] = A[r]; 
		A[r] = temp; 

		return i+1; 

  }

  public static void Sort(long A[], int l, int r) { 
      Random k = new Random();
	if(l<r) {     
          int lo = l;
          int hi = r;
          int m = k.nextInt(hi-lo) + lo;
          Sort(A,l,m-1);    
          Sort(A,m+1,r);
	} 
  } 


   public static void main(String args[]) { 
	Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int N = sc.nextInt(); 
        while(T-->0){
	  long[] A =new long[N];
          for(int i =0;i<N;i++){
             A[i] = sc.nextInt();  
          }

	     Sort(A, 0,N-1);

          for(int i=0;i<N;i++){ 
            System.out.print(A[i]);
          }
      } 
   } 
} 
