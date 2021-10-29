#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const long double PI = acos(-1);

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        if(!nums.size())return allSubsets;
        
        int n = nums.size();
        
        for(int i = 0; i<(1<<n); i++){
            
            vector<int> curSubset;
            for(int j = 0;  j<n;j++){
                
                if(i&(1<<j)){
                    curSubset.push_back(nums[j]);
                }
            }
            allSubsets.push_back(curSubset);
        }
        
        return allSubsets;
}

void solve(){
    int n;
    cin >> n;
    vector<int> set(n);
    for(int i = 0; i<n; i++){
        cin >> set[i];
    }
    
    auto allSubsets = subsets(set);
    cout << allSubsets.size() << endl;
    for(auto v:allSubsets){
        for(auto num:v){
            cout << num << " ";
        }
        cout << endl;
    }
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

 
    
