/**
(coin change 2)print the combinations to reach a sum using given coins
**/

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const long double PI = acos(-1);

void solve(){
    int sum;
    cin >> sum;
    int n;
    cin >> n;
    vector<int>coins(n);
    for(int i = 0;i <n; i++){
        cin >> coins[i];
    }
    
    map<int,vector<vector<int>>>m; //store all combination to reach a particular amount/sum
    for(int i = 0; i<n; i++){
        for(int curAmount = coins[i]; curAmount<=sum; curAmount++){
            if(curAmount==coins[i]){
                vector<int>tmp;
                tmp.push_back(curAmount);
                m[curAmount].push_back(tmp);
            }
            else{
                for(auto v:m[curAmount-coins[i]]){
                    v.push_back(coins[i]);
                    m[curAmount].push_back(v);
                }
            }
        }
    }
    
    for(auto v:m[sum]){
        for(auto i:v){
            cout << i << " ";
        }
        cout << endl;
    }
} 

signed main() 
{   
    IOS;
    
    int t = 1;
    cin >> t;

    for(int i = 1;i<=t;i++){

        solve();
    }
    return 0;
} 

 
    
