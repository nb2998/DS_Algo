#include<bits/stdc++.h>
using namespace std;

void swap(int&a, int&b)
{
    int t = a;
    a = b;
    b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
       if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Driver program to test above functions
int main()
{
int size, arr[10000];
cin>>size;
for(int i=0;i<=size-1;i++)
    cin>>arr[i];
quickSort(arr, 0, size-1);
for(int i=0;i<=size-1;i++)
    cout<<arr[i]<<" ";
}
