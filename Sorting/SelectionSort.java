import java.util.Arrays;

public class SelectionSort {
	public static void main(String[] args) {
		int[] arr = {1, 2, 5, 3, 4, 6};
		SelectionSort.sort(arr);
		System.out.println(Arrays.toString(arr));
	}

	public static void swap(int[] arr, int index1, int index2) {
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	public static void sort(int[] arr) {
		for(int i = 0; i < arr.length; i++) {
			swap(arr, i, findSmallest(arr, i));
		}
	}

	public static int findSmallest(int[] arr, int start) {
		int toReturn = start;

		for(int i = start; i < arr.length; i++) 
			if(arr[i] < arr[toReturn])
				toReturn = i;
		
		return toReturn;
	}
}