//  Problem Statement:

//  1) N no of children
//  2) Each one gets a candy
//  3) Children with higher rating gets more candies than neighbour


//  How to approach the problem:

//  Initially we have a candies1 array and all assigned to 1
//  Do a Left scan of the array and if arr[i]>arr[i-1],then candies1[i]=1+candies1[i-1].


// Initially we have a candies2 array and all assigned to 1
//  Then we will do a right scan and if arr[i]>arr[i+1],then candies2[i]=1+candies2[i+1].

// Then we find the maximum of two arrays candies1 and candies2.

//  We add this maximum array to get the result


# include <bits/stdc++.h>
using namespace std;

int candy(vector <int> &A){
vector <int> left(A.size(),1);
    vector <int> right(A.size(),1);
    
    int n=A.size();
    for(int i=1;i<n;i++){
        if(A[i]>A[i-1])
            left[i]=left[i-1]+1;
    }
    
   
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]>A[i+1])
            right[i]=right[i+1]+1;
    }
    
    int res=0;
    for(int i=0;i<n;i++){
        res+=max(left[i],right[i]);
    }
    return res;
}

int main(){

	
	int n;
	cin>>n;
	vector <int> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	cout<<candy(A)<<endl;




	return 0;
}


