#include <bits/stdc++.h>
using namespace std;

int ternarySearch(int, int, int, int[]);

int main()
{

    int arraySize;
    cin >> arraySize;
    int *A = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        cin >> A[i];
    }

    int searchElement;
    cin >> searchElement;

    //ternary search
    int index = ternarySearch(0, arraySize - 1, searchElement, A);
    if (index == -1)
    {
        cout << "Element " << searchElement << " not found in the array." << endl;
    }
    else
    {
        cout << "Element " << searchElement << " found at index " << index << "." << endl;
    }
    return 0;
}

int ternarySearch(int leftIndex, int rightIndex, int key, int arr[])
{
    if (leftIndex <= rightIndex)
    {
        int midOneIndex = leftIndex + (rightIndex - leftIndex) / 3;
        int midTwoIndex = rightIndex - (rightIndex - leftIndex) / 3;

        if (arr[midOneIndex] == key)
        {
            return midOneIndex;
        }

        if (arr[midTwoIndex] == key)
        {
            return midTwoIndex;
        }

        if (arr[midOneIndex] > key)
        {
            return ternarySearch(leftIndex, midOneIndex - 1, key, arr);
        }
        else if (arr[midTwoIndex] < key)
        {
            return ternarySearch(midTwoIndex + 1, rightIndex, key, arr);
        }
        else
        {
            return ternarySearch(midOneIndex + 1, midTwoIndex - 1, key, arr);
        }
    }
    // key not found
    return -1;
}