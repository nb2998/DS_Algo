#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
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
