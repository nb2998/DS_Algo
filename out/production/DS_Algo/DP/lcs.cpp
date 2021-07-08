#include <bits/stdc++.h>

using namespace std;

int main(){

     string s1,s2; // declaring two strings
     cout << "Enter the first String" << endl; 
     cin >> s1; //take first string as input
     cout << "Enter the second String" << endl;
     cin >> s2; // take second string as input

     int m=s1.length(); // length of string 1
     int n=s2.length(); // length of string 2

     int mat[m+1][n+1]; // declaring matrix of size (m+1)(n+1)
     
     vector<char> v1; // declaring vector for storing the common elements
     for(int i=0;i<m+1;i++){ //looping for 1 row

     	for(int j=0;j<n+1;j++) // looping for 1 cloumn
     	{
     		if(i==0 || j==0) // making 0 the elemnts of first row and column
     		{
               mat[i][j]=0;
     		}
     		else
     		{
     			if(s1[i-1]==s2[j-1]) // if character matches in both the string
     			{
     				mat[i][j]=mat[i-1][j-1]+1;// increse the value of elemnet by 1 from the digonal element
                   // v1.push_back(s1[i-1]);
     			}
     			else
     			{
     				mat[i][j]=max(mat[i-1][j],mat[i][j-1]); // else if string elements are not same then take maximum value from upside or leftside
     			}

     		}
     	}
     }

     int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      
      if (s1[i-1] == s2[j-1]) // If current character in s1 and s2 are same, then current character is part of LCS 
      { 
          v1.push_back(s1[i-1]); // Put current character in result 
          i--; j--;               // reduce values of i, j and index 
      } 
  
      else if (mat[i-1][j] > mat[i][j-1])  // If not same, then find the larger of two and go in the direction of larger value 
         i--; 
      else
         j--; 
   } 

     cout << "The longest common subsequence is:" << endl; // printing out the common subsequence 
     for (int i = v1.size()-1; i>=0; i--) 
        cout << v1[i]; 
  
    cout << endl;
}