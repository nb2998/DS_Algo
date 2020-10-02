#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std; 
  
// Function to sort arr[] of size n using bucket sort 
void bucketSort(float arr[], int n) 
{ 
    // Create n empty buckets 
    vector<float> b[n]; 
  
    // Put array elements in different buckets 
    for (int i = 0; i < n; i++) { 
        int bi = arr[i]/10; // Index in bucket
        b[bi].push_back(arr[i]); 
    } 
  
    // Sort individual buckets 
    for (int i = 0; i < n; i++) 
        sort(b[i].begin(), b[i].end()); 
  
    // Concatenate all buckets into arr[] 
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
            arr[index++] = b[i][j]; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    float arr[] = {32,94,48,0,52,21,93,85,12,76}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bucketSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
}