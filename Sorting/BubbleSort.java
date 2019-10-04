import java.util.Arrays;

public class BubbleSort {
	
	public static void main(String[] args) {
		int[] arr = {1, 4, 2, 3, 6, 5};
		bubbleSort(arr);
		System.out.println(Arrays.toString(arr));
	}

	public static void bubbleSort(int[] arr) {
        boolean swap = true;
        int i = 0;

        while(swap && i < arr.length){
            swap = false;
            for(int j=i; j<arr.length-1; j++){
                if(arr[j] > arr[j+1]){
                    swap = swap(arr, j, j+1);
                }
            }
            i++;
        }
	}

	public static boolean swap(int[] arr, int index1, int index2) {
		int temp = arr[index1];
		arr[index1] = arr[index2];
        arr[index2] = temp;
        return true;
	}
}