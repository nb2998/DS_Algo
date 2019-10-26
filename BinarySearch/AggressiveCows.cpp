#include<bits/stdc++.h>
using namespace std;
int bs(int arr[],int n,int c,int low,int high)
{
    int mid;
    int ans=0;
    while(low<=high)
    {
        int count=1;
        mid=(low+high)/2;
        int fi=arr[0];
        for(int k=1;k<n;k++)
        {
            if(arr[k]-fi>=mid)
            count++,fi=arr[k];
        }
        if(count>=c)
        ans=mid,low=mid+1;
        else
        high=mid-1;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(arr,arr+n);
        int low= 1;
        int high= arr[n-1]-arr[0];
        cout<<bs(arr,n,c,low,high)<<endl;
    }
    return 0;
}
