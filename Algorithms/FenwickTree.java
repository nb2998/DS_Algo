import java.util.Arrays;

public class FenwickTree {

	final static int MAX = 100;
	/**
	 * Array to hold the the BITree
	 */
	static long BITree[] = new long[MAX];

	static long getSum(int index) {
		long sum = 0;
		index = index + 1;
		// Traversing ancestors
		while (index > 0) {
			sum += BITree[index];
			index -= index & (-index);		//traverse upto the zeroth index
		}
		return sum;
	}

	static void updateBIT(int n, int index, int val) {
		index = index + 1;
		while (index <= n) {
			BITree[index] += val; 
			index += index & (-index);
		}
	}
	static void constructBITree(int arr[], int n) 
    { 
		for(int i=1; i<=n; i++) 
            BITree[i] = 0; 
    
        for(int i = 0; i < n; i++) 
            updateBIT(n, i, arr[i]); 
    } 
	
	public static void main(String args[]) {
		int arr[] = {1,2,3,5,8,-1,7,8};
		FenwickTree ft = new FenwickTree();
		ft.constructBITree(arr, arr.length);
		System.out.println("Sum upto index 4: "+ft.getSum(4));
		System.out.println("Sum between index 2 and 5: "+(ft.getSum(5)-ft.getSum(1)));
		ft.updateBIT(arr.length, 2, -3); 
		System.out.println("Sum between index 2 and 5: "+(ft.getSum(5)-ft.getSum(1)));
	}
}
