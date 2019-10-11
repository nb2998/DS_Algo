#include<bits/stdc++.h>
#define Loop(i,a,b) for(int i=a;i<b;++i)
#define NLoop(i,a,b) for(int i=a;i>=b;--i)
#define print(arr,n,m) for(int i=0;i<n;++i) { for(int j=0;j<m;++j) cout<<arr[i][j]<<" "; cout<<endl; }
#define print2(arr,n) for(int i=0;i<n;++i) { cout<<arr[i]<<" "; } cout<<endl;
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007
#define pb(x) push_back(x)
#define ub(x,el) upper_bound(x.begin(),x.end(),el) - x.begin()
#define lb(x,el) lower_bound(x.begin(),x.end(),el) - x.begin();
#define bs(x,el) binary_search(x.begin(),x.end(),el)
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b) { if (b == 0) return a; return gcd(b, a % b);  }

ll power(ll x,ll y, ll p) { ll res = 1; x = x % p; while (y > 0) { if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p;   } return res; } 
//class compare { public: bool operator() (ll a,ll b) { return a>b;};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
		
		ll n;
		cin>>n;
		vector<ll> arr(n);
		for(ll i=0;i<n;++i) cin>>arr[i];
		vector<ll> par(n);
		vector<ll> tail(n);
		tail[0] = 0;
		par[0] = -1;
		ll length = 1;
		for(ll i=1;i<n;++i)
		{
			ll lo = 0;
			ll hi = length-1;
			while(lo<=hi)
			{
			//	cout<<lo<<" "<<hi<<endl;
				ll mid = (lo+hi)>>1;
				ll j = tail[mid];
				if(arr[j] < arr[i]) lo = mid+1;
				else hi = mid-1;
			}
			ll pos = lo;
			tail[pos] = i;
			if(pos==0) par[i] = -1;
			else par[i] = tail[pos-1];
			if(pos==length) ++length;
		//	print2(tail,tail.size());
		}
		cout<<length<<endl;
		stack<ll> st;
		ll i = tail[length-1];
		while(i!=-1)
		{
			st.push(arr[i]);
			i = par[i];
		}
		while(!st.empty())
		{
			cout<<st.top()<<" ";
			st.pop();
		}
		cout<<endl;
	}
}