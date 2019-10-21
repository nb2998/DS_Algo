#include <bits/stdc++.h> 
using namespace std; 

void CocktailSort(int a[], int n) 
{ 
	bool swapped = true; 
	int start = 0; 
	int end = n - 1; 

	while (swapped) { 
	
		swapped = false; 

	
		for (int i = start; i < end; ++i) { 
			if (a[i] > a[i + 1]) { 
				swap(a[i], a[i + 1]); 
				swapped = true; 
			} 
		} 

		if (!swapped) 
			break; 

		
		swapped = false; 

	
		--end; 

	
		for (int i = end - 1; i >= start; --i) { 
			if (a[i] > a[i + 1]) { 
				swap(a[i], a[i + 1]); 
				swapped = true; 
			} 
		} 

		
		++start; 
	} 
} 


void printArray(int a[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout<<a[i]; 
	cout<<"\n"; 
} 

int main() 
{ 
	int n ; 
	cin>>n ; 
	int arr[n];
	for(int i = 0 ; i<n ; i++)
	{
		cin>>arr[i];
	}
	CocktailSort(arr, n); 
	cout<<"Sorted array :\n"; 
	printArray(arr, n); 
	return 0; 
} 
