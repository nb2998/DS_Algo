#include<iostream>
#include<vector>
using namespace std;
void heapify(int * arr,int i,int n){
    int left = 2*i;
    int right = 2*i+1;
    int minIndex = i;
     if(left<n && arr[minIndex] > arr[left]){
            minIndex = left;
        }
        if(right<n && arr[minIndex] > arr[right]){
            minIndex = right;
        }
        if(minIndex!=i){
            swap(arr[i],arr[minIndex]);
            heapify(arr,minIndex,n);
        }
        return;
}
void heapSort(int * arr,int n){
    // construct heap
    for(int i=n/2;i>0;i--){
        heapify(arr,i,n);
    }
    // extract min
    // place at last
    // heapify
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[1]);
        heapify(arr,1,i);
    }
}
int main(){
int arr[10] = {-1,5,8,2,4,1};
heapSort(arr,6);
for(int i=1;i<6;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
