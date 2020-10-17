public class Bubblesort {
    private void swap(int[] arr, int a){
        int temp = arr[a];
        arr[a] = arr[a+1];
        arr[a+1] = temp;
    }

    private int[] sorting(int[] arr, max) {
        boolean flag = False;
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                flag = True;
                swap(arr, i)
            }
        }
        if (flag == True) sorting(arr, max - 1);
        return arr;
        }
    }