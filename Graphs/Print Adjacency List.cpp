#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void printgraph(vector<int> adj[], int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i;
        for(auto x : adj[i]) 
           cout<<"-> "<<x; 
        printf("\n");
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int v, e;
        cin>>v>>e;
        int x, y;
        vector<int> adj[v];
        for(int j=0;j<e;j++)
        {
            cin>>x>>y;
            addedge(adj,x,y);
        }
        printgraph(adj, v);
    }
}

