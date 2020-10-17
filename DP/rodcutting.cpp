#include<iostream>
#include<climits>
using namespace std;

int cutRod(int price[], int n) 
{ 
int val[n+1]; 
val[0] = 0; 
int i, j; 

for (i = 1; i<=n; i++) 
{ 
	int max_val = INT_MIN; 
	for (j = 0; j < i; j++) 
		max_val = max(max_val, price[j] + val[i-j-1]); 
	val[i] = max_val; 
} 

return val[n]; 
} 


int main() 
{ 
	int arr[] = {1, 2, 5, 9, 10, 15, 17, 20}; 
	int size = sizeof(arr)/sizeof(arr[0]); 
	cout<<"Max val is "<< cutRod(arr, size);
	return 0; 
} 
