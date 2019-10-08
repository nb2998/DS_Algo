package codeforces;

/**
 * @author johnny16
 *
 */
public class FenwickTree {

	final static int MAX = 100;

	static long BITree[] = new long[MAX];

	static long getSum(int index) {
		long sum = 0;
		index = index + 1;
		// Traversing ancestors
		while (index > 0) {
			sum += BITree[index];
			index -= index & (-index);
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
	
}
