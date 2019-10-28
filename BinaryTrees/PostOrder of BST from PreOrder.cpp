#include <bits/stdc++.h> 
using namespace std; 
void findvector(int pre[], int n, int min, int max, int &preIndex, vector<int> &v)
{
    if(preIndex==n)
        return;
    if(pre[preIndex]<min || pre[preIndex]>max)
    {
        return;
    }
    int val = pre[preIndex];
    preIndex++;
    
    findvector(pre, n, min, val, preIndex,v);
    findvector(pre, n, val, max, preIndex,v);
    v.push_back(val);
}

vector<int> findpostorder(int pre[], int n)
{
    vector<int> v;
    int preIndex = 0;
    findvector(pre, n, INT_MIN, INT_MAX, preIndex, v);
    return v;
}
int main() 
{ 
    int pre[] = { 40, 30, 35, 80, 100 }; 
  
    int n = sizeof(pre) / sizeof(pre[0]); 
  
    vector<int> v;
    // Calling function 
    v = findpostorder(pre, n); 
    int i ;
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}

