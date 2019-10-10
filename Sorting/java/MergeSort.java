
import java.io.*;
import java.util.*;
import java.util.Scanner;

public class MergeSort 
{ 

  public static void Merge(int[] A, int l, int m, int r){

        int n1 = m-l+1; 
        int n2 = r-m; 
        int L[] = new int [n1]; 
        int R[] = new int [n2]; 
  
        for (int i=0; i<n1; ++i){ 
            L[i] = A[l+i];
        } 
        for (int j=0; j<n2; ++j){ 
            R[j] = A[m+1+j];
        } 
   
        int i=0, j=0;  
        int k=l; 
        while (i<n1 && j<n2){ 
            if (L[i]<=R[j]){
                A[k]=L[i]; 
                i++; 
            } 
            else{
                A[k]=R[j]; 
                j++; 
            } 
            k++; 
        } 
        while (i<n1){ 
            A[k] = L[i]; 
            i++; 
            k++; 
        } 
        while (j<n2){ 
            A[k]=R[j]; 
            j++; 
            k++; 
        } 
  
  }
  public static void Sort(int A[], int l, int r) 
  { 
	if(l<r) 
	{     
          int m = (l+r)/2;
          Sort(A,l,m);    
          Sort(A,m+1,r);
          Merge(A,l,m,r); 
	} 
  } 

   public static void main(String args[]) { 
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int[] A =new int[N];
        for(int i =0;i<N;i++){
          A[i] = sc.nextInt();  
        }

	 Sort(A,0,N-1);

        for(int i=0;i<N;i++){ 
          System.out.print(A[i]);        
        } 
   } 
}
