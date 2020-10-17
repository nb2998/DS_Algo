#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)                   for( int i = 0 ; i < n ; i++)
#define repu(i,a,b)                for(int i = a ; i <= b ; i++) 
#define repd(i,b,a)                for(int i = b ; i >= a ; i--)
typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii > viii ;
#define fi first
#define se second
#define pb push_back

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
        if(root_A!=root_B) {
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

}
    
void printCC(int arr[], int size[], int n) {
    vector<pair<int, int>> v;
    rep(i,n) {
        if(root(arr,i)==i) v.pb(make_pair(size[i], arr[i]));
    }
    sort(v.begin(), v.end());
    rep(i,v.size()) cout<<v[i].fi<<" ";
    cout<<endl;
}

int main() {
    int n, m; cin>>n>>m;
    int arr[n], size[n];
    initialise(arr, size, n);
    rep(i,m) {
        int x,y; cin>>x>>y;
        wd_union(arr, size,x-1,y-1);
        printCC(arr,size,n);
    } 
    
}