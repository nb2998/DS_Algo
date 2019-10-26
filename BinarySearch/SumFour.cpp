#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 10000001
int k,p;
int e[MAX];
int f[MAX];
int binarysearch(int val)
{
    int size=0,temp=0,low=0,high=k,mid;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(e[mid]==val)
        {
            temp=mid-1;
            while(mid<k&&e[mid]==val)
            {
                size++;
                mid++;
            }
            while(temp>=0&&e[temp]==val)
            {
                size++;
                temp--;
            }
            return size;
        }
        else if(e[mid]>val)
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}
int main()
{
    int n,i,j;
    int a[4000],b[4000],c[4000],d[4000];//e[1000000],f[1000000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
    p=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            e[p]=a[i]+b[j];
            p=p+1;
        }
    }
    sort(e,e+p);
    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            f[k]=(c[i]+d[j])*-1;
            k=k+1;
        }
    }
    sort(f,f+k);
    int size1,size2,temp,count=0;
    for(i=0;i<k;)
    {
        size1=0;
        temp=f[i];
        while(f[i]==temp&&i<k)
        {
            size1++;
            i++;
        }
        size2=binarysearch(temp);
        count+=size1*size2;
    }
    printf("%d\n",count);
    return 0;
}
