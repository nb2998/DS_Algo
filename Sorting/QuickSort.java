/*
 * Developed by Atri Tripathi on 14/7/19 9:39 PM
 * Last modified 13/7/19 10:55 PM
 * Copyright (c) 2019. All rights reserved
 */

public class QuickSort {
    private void swap(int[] arr, int indexOne, int indexTwo) {
        int temp = arr[indexOne];
        arr[indexOne] = arr[indexTwo];
        arr[indexTwo] = temp;
    }
    private int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr,i,j);
            }
        }
        i++;
        swap(arr,i,high);
        return i;
    }

    // This is the normal sort function, which has worst space case Space Complecity: O(n)
    private void sort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr,low,high);

            sort(arr,low,pi-1);
            sort(arr,pi+1,high);
        }
    }

    // This is the optimized version which uses Tail Call Elimination to reduce the Space Complexity to: O(log n)
    private void sortOptimized(int[] arr, int low, int high) {
        while (low < high) {
            int pi = partition(arr,low,high);

            // If left part is smaller, then recur for left part
            if (pi - low < high - pi) {
                sortOptimized(arr, low, pi - 1);
                low = pi + 1;
            }
            // Else recur for right part
            else {
                sortOptimized(arr, pi + 1, high);
                high = pi - 1;
            }
        }
    }

    private void printArray(int[] arr) {
        for (int val: arr) {
            System.out.print(val + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int data[] = {7, 9, 5, 2, -5, -1, -2, 0, 4, 3};

        QuickSort quickSort = new QuickSort();
        quickSort.sort(data,0,data.length-1);
        quickSort.printArray(data);
    }
}