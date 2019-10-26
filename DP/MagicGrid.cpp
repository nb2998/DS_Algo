#include <bits/stdc++.h>
using namespace std;
int health(int **arr,int si,int sj,int r,int c)
{
    int **dp= new int*[r];
    for(int i=0;i<r;i++)
    {
        dp[i]=new int[c];
    }
    if(si==r&&sj==c)
    return arr[si][sj];
    dp[r-1][c-1]=1;
    for(int i=r-2;i>=0;i--)
    {
        dp[i][c-1]=dp[i+1][c-1]-arr[i][c-1];
        if(dp[i][c-1]<=0)
        dp[i][c-1]=1;
    }
    for(int j=c-2;j>=0;j--)
    {
        dp[r-1][j]=dp[r-1][j+1]-arr[r-1][j];
        if(dp[r-1][j]<=0)
        dp[r-1][j]=1;
    }
    for(int i=r-2;i>=0;i--)
    {
        for(int j=c-2;j>=0;j--)
        {
            dp[i][j]=min(dp[i+1][j],dp[i][j+1])-arr[i][j];
            if(dp[i][j]<=0)
            dp[i][j]=1;
        }
    }
    return dp[0][0];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        int **arr= new int*[r];
        for(int i=0;i<r;i++)
        arr[i] = new int[c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>arr[i][j];
            }
        }
        cout<<health(arr,0,0,r,c)<<endl;
        delete [] arr;
    }
    return 0;
}
