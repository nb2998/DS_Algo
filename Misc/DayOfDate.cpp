#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll getLeap(ll y, ll m)
{
	if(m>2) return y/4 - y/100 + y/400;
	return (y-1)/4 - (y-1)/100 + (y-1)/400;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll d1,m1,y1;
		ll d2,m2,y2;
		d2 = 12;
		m2 = 8;
		y2 = 2019;
		cin>>d1>>m1>>y1;
		vector<ll> arr = {31,28,31,30,31,30,31,31,30,31,30,31};
		
		ll count1 = y1*365;
		for(ll i=0;i<m1-1;++i) count1+= arr[i];
		count1+= d1;
		count1+= getLeap(y1,m1); 
		
			
		ll count2 = y2*365;
		for(ll i=0;i<m2-1;++i) count2+= arr[i];
		count2+= d2;
		count2+= getLeap(y2,m2); 
		vector<string> arr2 = {"Sunday", "Monday", "Tuesday", "Wednesday","Thursday","Friday","Saturday"};
		if(count2 > count1)
		{
			ll temp = (count2-count1)%7;
			temp = (7-temp)%7;
			cout<<arr2[(temp+1)%7]<<endl;
		}
		else
		{
			ll temp = (count1-count2)%7;
			cout<<arr2[(temp+1)%7]<<endl;
		}
		
	}
}
