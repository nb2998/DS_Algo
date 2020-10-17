#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii > viii ;
#define rep(i,n)                   for( int i = 0 ; i < n ; i++)
#define repu(i,a,b)                for(int i = a ; i <= b ; i++) 
#define repd(i,b,a)                for(int i = b ; i >= a ; i--)
#define pb push_back
#define db double 
#define fi first
#define se second

void initialise(int arr[], int size[], int n) {
    rep(i,n) {
        arr[i]=i;
        size[i]=1;
    }
}

int root(int Arr[],int i)
    {
        while(Arr[ i ] != i)           
        {
         i = Arr[ i ];
        }
        return i;
    }

void wd_union(int Arr[],int size[],int A,int B)
    {
        int root_A = root(Arr,A);
        int root_B = root(Arr,B);
        if(size[root_A] < size[root_B ])
        {
    Arr[ root_A ] = Arr[root_B];
    size[root_B] += size[root_A];
    }
        else
        {
    Arr[ root_B ] = Arr[root_A];
    size[root_A] += size[root_B];
    }

    }

ll kruksal(pair <long long, pair<int, int> > p[], int n, int m, int arr[], int size[]) {
	int x,y; 
	ll cost, minCost=0;
	rep(i,m) {
		x=p[i].se.fi;
		y=p[i].se.se;
		cost=p[i].fi;
		if(root(arr,x)!=root(arr,y)) {
			minCost+=cost;
			wd_union(arr,size,x,y);
		}
	}
	return minCost;
} 

int main() {
	int t; cin>>t;
	while(t--) {
		int pr,n,m; cin>>pr>>n>>m;
		pair <long long, pair<int, int> > p[m];
		int arr[m],size[m];
		initialise(arr,size,m);
		rep(i,m) {
			int a,b,c; cin>>a>>b>>c;
			p[i]={c,{a-1,b-1}};
		} 
		sort(p,p+m);
		cout<<kruksal(p,n,m,arr,size)<<endl;
	}
}