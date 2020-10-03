#include<iostream>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; } 

int knapSack(int W, int wt[], int val[], int n) {  
    int dp[W+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) { 
        for(int j=W; j>=wt[i]; j--) {
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);
	    } 
    } 
    return dp[W]; 
} 

int main() 
{ 
	int val[] = {60, 80, 90}; 
	int wt[] = {10, 20, 30}; 
	int W = 50; 
	int n = sizeof(val)/sizeof(val[0]); 
	cout<< knapSack(W, wt, val, n); 
	return 0; 
} 
