#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const long double PI = acos(-1);

bool check(int& mid, int& num, vector<int>& a){
    if(a[mid] >= num)return true;
    return false;
}

void solve(){
    int n;
    cin>> n;
    
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    
    int num; //we need to find the lower bound of num in the sorted vector a
    cin >> num;
    
    int start = 0, end = n-1;
    int lowerBound = 0;
    
    while(start<=end){
        int mid = (start+end)/2;
        bool flag = check(mid, num, a); //validation function 
        if(flag){
            lowerBound = a[mid];
            end = mid-1;
        }
        else
            start = mid+1;
    }
    cout << lowerBound << endl;
    
} 

signed main() 
{   
    IOS;
    
    int t = 1;
    // cin >> t;

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
} 

 
    
