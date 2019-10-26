#include<bits/stdc++.h>
using namespace std;
bool binary_search(int arr[],int low,int high,int val)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==val)
        return true;
        else if(arr[mid]<val)
        {
            low=mid+1;
        }
        else
        high=mid-1;
    }
    return false;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(binary_search(arr,i+1,n-1,arr[i]+k))
        ans++;
    }
    cout<<ans;
    return 0;
}
