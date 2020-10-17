#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)                   for( int i = 0 ; i < n ; i++)
#define repu(i,a,b)                for(int i = a ; i <= b ; i++) 
#define repd(i,b,a)                for(int i = b ; i >= a ; i--)
typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii > viii ;
#define pb push_back
#define fi first
#define se second
  
int n,s,e;

int minDistance(int dist[], int vis[]) {
	int mi=INT_MIN, min_index;
	rep(i,n) {
		if(vis[i]==false && dist[i]<=mi) mi=dist[i], min_index=i;
	}
	return min_index;
}

void dijkstra(int graph[][n], int src) {
	int dist[n];
	bool vis[n];
	memset(dist, INT_MAX, sizeof dist);
	memset(vis, false, sizeof vis);
	dist[src]=0;
	rep(i,n-1) {
		int u=minDistance(dist,vis);
		vis[u]=true;
		rep(j,n) {
			if(!vis[j] && graph[u][j] && dist[u]!=INT_MAX && dist[u]+graph[u][j]<dist[j])
			dist[j]=dist[u]+graph[u][j]; 
		}
	}
	cout<<dist[e-1]-dist[s-1]<<endl;
}

int main() {
	int t; cin>>t;
	while(t--) {
		int m; cin>>n>>m>>s>>e;
		int graph[n][n];
		rep(i,m) {
			int x,y,t; cin>>x>>y>>t;
			graph[x-1][y-1]=t;
		}
		djikstra(graph,s-1);
	}
}	