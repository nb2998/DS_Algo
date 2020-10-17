#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii > viii ;
#define rep(i,n)                   for( ll i = 0 ; i < n ; i++)
#define repu(i,a,b)                for(int i = a ; i <= b ; i++) 
#define repd(i,b,a)                for(int i = b ; i >= a ; i--)
#define pb push_back
#define db double 
#define fi first
#define se second

string s_max="";
string s_maxi="";

void lcs(string s, string t, int m, int n) {
	int L[m+1][n+1];
	rep(i,m+1) {
		rep(j,n+1) {
			if(i==0 || j==0) L[i][j]=0;
			else if(s[i-1]==t[j-1]) L[i][j]=L[i-1][j-1]+1;
			else L[i][j]=max(L[i-1][j], L[i][j-1]);
		}
	}
	int index = L[m][n]; 
	char lcs[index+1]; 
   	lcs[index] = '\0'; 
	int i=m, j=n;
	while(i>0 && j>0) {
		if(s[i-1]==t[j-1]) {
			lcs[index-1]=s[i-1];
			i--, j--, index--;
		} else if(L[i-1][j]>L[i][j-1]) i--;
		else j--;
	}
	cout<<lcs;
} 

int main() {
   string s,t; cin>>s>>t;
   lcs(s,t,s.length(),t.length());
}