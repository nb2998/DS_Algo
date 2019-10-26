#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int check(ll mid,ll arr[],ll n,ll m)
{
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]-mid>0)
        sum=sum+(arr[i]-mid);
    }
    if(sum>=m)
    return 1;
    else
    return 0;
}
ll bs(ll arr[],ll n,ll m)
{
    ll low=0;
    ll ans=0;
    ll high=arr[n-1];
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(check(mid,arr,n,m)==1)
        {
        low=mid+1;
        ans=mid;
        }
        else
        high=mid-1;
    }
    return ans;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    ll res=bs(arr,n,m);
    printf("%lld",res);
    return 0;
}
