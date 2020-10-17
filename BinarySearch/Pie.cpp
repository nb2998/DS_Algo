#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846264338327950
#define ld long double
int func(ld mid,ld vol[],int n,int f)
{
    int fr=0;
    if(mid==0)
    return 0;
    for(int i=0;i<n;i++)
    {
        fr+=(int)(vol[i]/mid);
    }
    if(fr>=f)
    return 1;
    else
    return 0;
}
ld bs(ld vol[],int n,int f)
{
    ld low=0;
    ld high=vol[n-1];
    while(high-low>=1e-6)
    {
        ld mid=(low+high)/2;
        if(func(mid,vol,n,f)==1)
        low=mid;
        else 
        high=mid;
    }
    return low;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,f;
        cin>>n>>f;
        f=f+1;
        ld arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        ld vol[n];
        for(int i=0;i<n;i++)
        vol[i]=arr[i]*arr[i]*pi;
        sort(vol,vol+n);
        ld res = bs(vol,n,f);
        printf("%0.4Lf\n",res);
    }
    return 0;
}
