INVCNT - Inversion Count(SPOJ)
#graph-theory #number-theory #shortest-path #sorting #bitmasks


CODE:

#include<bits/stdc++.h>
using namespace std;
#define ld long long 
void merge(ld arr[],ld n,ld low,ld mid,ld high,ld &count)
{
    ld n1=mid-low+1;
    ld left[n1];
    ld i,j,k;
    for(i=0;i<n1;i++)
    {
        left[i]=arr[i+low];
    }
    ld n2=high-mid;
    ld right[n2];
    for(i=0;i<n2;i++)
    {
        right[i]=arr[mid+1+i];
    }
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            k++;
            i++;
        }
        else
        {
            count+=n1-i;
            arr[k]=right[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        k++;
        j++;
    }
}
void mergesort(ld arr[],ld n,ld low,ld high,ld &count)
{
    if(low<high)
    {
    ld mid=(low+high)/2;
    mergesort(arr,n,low,mid,count);
    mergesort(arr,n,mid+1,high,count);
    merge(arr,n,low,mid,high,count);
    }
}
int main()
{
    ld t;
    cin>>t;
    while(t--)
    {
        ld n;
        cin>>n;
        ld arr[n];
        for(ld i=0;i<n;i++)
        cin>>arr[i];
        ld count=0;
        mergesort(arr,n,0,n-1,count);
        cout<<count<<endl;
    }
    return 0;
}
