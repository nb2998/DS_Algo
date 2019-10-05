package sorting;

public class BinarySearch {

	public static int binarySearch(int value, int[] array, int left, int right) {
		
		if (left > right) {
			return -1;
		}
		
		else {
			int mid = left + right;
			
			if (value == array[mid]) {
				return mid;
			}
			
			else if (value > array[mid]) {
				return binarySearch(value, array, mid + 1, right);
			}
			
			else {
				return binarySearch(value, array, left, mid - 1);
			}
		}
	}
	
	
	public static void main(String[] args) {
		int[] array = new int[] {0,2,3,4,6,7,8,9};
		
		System.out.println(binarySearch(1, array, 0, array.length - 1));
		System.out.println(binarySearch(0, array, 0, array.length - 1));
		System.out.println(binarySearch(9, array, 0, array.length - 1));
		System.out.println(binarySearch(6, array, 0, array.length - 1));
	}

}
