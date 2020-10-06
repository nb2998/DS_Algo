import java.util.Scanner;

public class MaximumSubArraySum {
//find maximum sub array sum
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
	
			int n = sc.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
			}
			
			
			//use kadne'e algorithm
			int mc = a[0];//maximum current
			int mg = a[0];//maximum global
			for(int i=1;i<n;i++) {
				mc = Math.max(a[i],mc+a[i]);//check if current element is greater than the previous maximum subarray + current element
				if(mc>mg) {//if maximum current is greater than maximum global then set mg as mc
					mg = mc;
				}
			}			
			
			System.out.println(mg);

		
	}

}
