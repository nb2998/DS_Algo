#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PRECISION std::cout << std::fixed << std::setprecision(20)
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define MOD 1000000007
#define mod 100000000
#define INF 1e18
#define BITS 20
using namespace __gnu_pbds;
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
bool v[MAXN];
void dfs(int start, vector<int> &v1){
	v[start] = true;
	v1.push_back(start);
	for(auto x : adj[start]){
		if(!v[x]){
			dfs(x, v1);
		}
	}
}
int main(){ 
	int n, m;
	cout<<"Enter the number of vectices : ";
	cin>>n;
	cout<<"Enter number of edges : ";
	cin>>m;
	int x,y;
	for(int i=0;i<m;i++){
		cout<<"Enter edge "<<i+1<<" : ";
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(v, false, sizeof(v));
	vector<vector<int>> ans;
	int cc = 0;
	for(int i=1;i<=n;i++){
		if(!v[i]){
			vector<int> v1;
			dfs(i,v1);
			ans.push_back(v1);
			cc++;
		}
	}
	cout<<"There are "<<cc<<" connected components\n";
	for(int i=0;i<cc;i++){
		cout<<"DFS for connected component "<<i+1<<" : ";
		for(auto x: ans[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
    return 0;
}
