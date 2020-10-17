#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000000
long long int prime[SIZE];
long long int fibo[SIZE];
void init()
{
    prime[0]=0;
    prime[1]=0;
    for(long long int i=2;i<SIZE;i++)
    prime[i]=1;
    for(long long int i=2;i<SIZE;i++)
    {
        long long int j;
        long long int t=2;
        j=i*t;
        while(j<SIZE)
        {
            prime[j]+=i;
            t++;
            j=i*t;
        }
    }
    fibo[0]=0;
    fibo[1]=0;
    for(long long i=2;i<SIZE;i++)
    {
        fibo[i]=fibo[i-1]+prime[i];
    }
}
int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long idx;
        scanf("%lld",&idx);
        printf("%lld\n",fibo[idx]);
    }
    return 0;
}
