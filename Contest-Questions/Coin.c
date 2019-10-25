//Given an integer X and an array arr[] of length N consisting of positive integers, the task is to pick minimum number of integers from the array such that they sum up to N.
//Any number can be chosen infinite number of times. 
//If no answer exists then print -1.
// C++ implementation of the approach 

//Input: X = 7, arr[] = {3, 5, 4}
//Output: 2
//The minimum number elements will be 2 as
//3 and 4 can be selected to reach 7.
//Input: X = 4, arr[] = {5}
//Output: -1

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the minimum number 
// of integers required 
int minNumbers(int x, int* arr, int n) 
{ 
	// Queue for BFS 
	queue<int> q; 

	// Base value in queue 
	q.push(x); 

	// Boolean array to check if a number has been 
	// visited before 
	unordered_set<int> v; 

	// Variable to store depth of BFS 
	int d = 0; 

	// BFS algorithm 
	while (q.size()) { 

		// Size of queue 
		int s = q.size(); 
		while (s--) { 

			// Front most element of the queue 
			int c = q.front(); 

			// Base case 
			if (!c) 
				return d; 
			q.pop(); 
			if (v.find(c) != v.end() or c < 0) 
				continue; 

			// Setting current state as visited 
			v.insert(c); 

			// Pushing the required states in queue 
			for (int i = 0; i < n; i++) 
				q.push(c - arr[i]); 
		} 

		d++; 
	} 

	// If no possible solution 
	return -1; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 3, 3, 4 }; 
	int n = sizeof(arr) / sizeof(int); 
	int x = 7; 

	cout << minNumbers(x, arr, n); 

	return 0; 
} 
