/*
 * Developed by Atri Tripathi on 14/7/19 9:39 PM
 * Last modified 14/7/19 9:39 PM
 * Copyright (c) 2019. All rights reserved
 */

public class MergeSort {
    private void sort(int[] arr, int lb, int ub) {
        if (lb < ub) {
            int mid = (lb + ub)/2;
            sort(arr,lb,mid);
            sort(arr,mid+1,ub);

            merge(arr,lb,mid,ub);
        }
    }

    private void merge(int[] arr, int lb, int mid, int ub) {
        int i=lb, j=mid+1, k=lb;
        int[] tempArr = new int[arr.length];

        while (i <= mid && j <= ub) {
            if (arr[i] <= arr[j])
                tempArr[k++] = arr[i++];
            else
                tempArr[k++] = arr[j++];
        }

        while (i <= mid)
            tempArr[k++] = arr[i++];
        
        while (j <= ub)
            tempArr[k++] = arr[j++];

        for (int l = lb; l <= ub; l++) {
            arr[l] = tempArr[l];
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

        MergeSort mergeSort = new MergeSort();
        mergeSort.sort(data,0,data.length-1);
        mergeSort.printArray(data);
    }
}