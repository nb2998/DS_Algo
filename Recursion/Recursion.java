package Lec1;

import java.util.ArrayList;

public class Recursion {
	
	static int fibonacci(int n) {
		if(n==0||n==1) return n;
		return fibonacci(n-1)+fibonacci(n-2);
	}
	
	static int power(int x, int n) {
		if(n==0) return 1;
int ans=power(x,n/2);
		ans*=ans;
		return n%2==0?ans:ans*x;
	}
	
	static int fact(int n) {
		if(n==0 || n==1) return n;
		return n*fact(n-1);
	}
	
	static void printDISkip(int n) {
		if(n==0) return;
		if(n%2!=0) System.out.println(n);
		printDISkip(n-1);
		if(n%2==0) System.out.println(n);
	}
	
	static long factUsingDp(int n) {
		long[] store =new long[n+1];
		store[0]=1; store[1]=1;
		for(int i=2; i<=n; i++) store[i]=store[i-1]*i;
		return store[n];
	}

	static boolean isArraySorted(int[] arr, int si) {
		if(si==arr.length-1) return true;
		if(arr[si+1]<arr[si]) return false; 
		return isArraySorted(arr, si+1);
	}
	
	static int firstIndex(int[]arr, int si, int data) {
		if(si>arr.length-1) return -1;
		if(arr[si]==data) return si;
		return firstIndex(arr, si+1, data);
	}
	
	// REVISE TODO last index and all indices
	static int lastIndex(int[] arr, int si, int data) {
		if(si>arr.length-1) return -1;
		
		int index=lastIndex(arr, si+1, data);
		if(index==-1) {
			if(arr[si]==data) return si;  // changes value of index so that in next call, comes in else and returns
			else return -1;
		} else return index;  // if previous element returns index!=-1, i.e element found ; return index
	}
	
	static int[] allIndices(int[] arr, int si, int data, int count) {
		if(si>arr.length-1) return new int[count];
		int[] indices=null;
		if(arr[si]==data) indices= allIndices(arr, si+1, data, count+1);
		else indices=allIndices(arr, si+1, data, count);
		if(indices!=null) {
			if(arr[si]==data) indices[count]=si;
		}
		return indices;
	}
	
	static int[] allIndicesR(int[] arr, int si, int data, int count) {
		if(si>arr.length-1) return new int[count];
		if(arr[si]==data) return allIndices(arr, si+1, data, count+1);
		int[] indices = allIndices(arr, si+1, data, count);
		if(arr[si]==data) indices[count] = data;
		return indices;
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		System.out.println(fibonacci(5));
//		System.out.println(power(2,5));
//		printDISkip(5);
//		System.out.println(factUsingDp(20));
		System.out.println(fact(5));
		int[] arr= {1, 5, 9, 10, 9, 6 ,5 ,9};
		int[] arr1= {1, 5, 9, 10};
		System.out.println(isArraySorted(arr1, 0));
		System.out.println(firstIndex(arr, 0, 9));
		System.out.println(firstIndex(arr, 0, 2));
		System.out.println(lastIndex(arr, 0, 9));
		System.out.println(lastIndex(arr, 0, 2));
		int[] indices=allIndicesR(arr, 0, 9, 0);
		for(int i=0; i<indices.length; i++) System.out.print(indices[i]+" ");
	}
	
	

}
