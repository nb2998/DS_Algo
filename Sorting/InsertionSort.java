import java.util.Arrays;

public class InsertionSort {
	
	public static void main(String[] args) {
		int[] arr = {1, 4, 2, 3, 6, 5};
		InsertionSort.insertionSort(arr);
		System.out.println(Arrays.toString(arr));
	}

	public static void insertionSort(int[] arr) {
		for(int i = 1; i < arr.length; i++) {
			int key = i;
			while(key > 1 && arr[key] < arr[key-1]) 
				swap(arr, key-1, key);
			
		}
	}

	public static void swap(int[] arr, int index1, int index2) {
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}