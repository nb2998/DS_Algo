#include<bits/stdc++.h>
using namespace std;

void swap(long int&a, long int &b)
{
    long int tmp = a;
    a = b;
    b = tmp;
}

void selection_sort(long int arr[], long int size)
{
    for(int i=0;i<=size-1;i++)
    {
        long int min_index = i;
        for(long int j=i+1;j<=size-1;j++)
        {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

int main()
{
long int size, arr[10000];
cin>>size;
for(int i=0;i<=size-1;i++)
    cin>>arr[i];
selection_sort(arr, size);
for(int i=0;i<=size-1;i++)
    cout<<arr[i]<<" ";
}
