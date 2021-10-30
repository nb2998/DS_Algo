#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target ("avx2,avx,fma")
typedef long long int ll;
typedef pair <int,int> ii ;
typedef vector < int > vi ;
typedef vector < ii > vii ;
#define rep(i,n)                   for(int i = 0 ; i < n ; i++)
#define repu(i,a,b)                for(int i = a ; i <= b ; i++) 
#define repd(i,b,a)                for(int i = b ; i >= a ; i--)
#define pb push_back
#define fi first
#define se second
#define all(p)                p.begin(),p.end()
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Endl endl
inline ll poww(ll a,ll b){ll r=1LL;while(b>0){if(b&1)r=r*a;b/=2;a=a*a;}return (int)r;}
template <class T>inline void sary(T st, T nd){while(st<nd)cin>>*st++;/*sf("%d", st++);*/}
const int mod=1e9+7;
inline ll mul(ll a, ll b){return ((a%mod)*(b%mod))%mod;}
inline ll add(ll a, ll b){return ((a%mod)+(b%mod))%mod;}
inline ll sub(ll a, ll b){return ((a%mod)-(b%mod)+mod)%mod;}
const int N= 51*51+1; 

class Solution {
public:
    int subarraySum(vector<int> v, int k) {
        if(v.empty()) return 0;
        int n=v.size(), c=0,s=0;
        map<int,int> ma; ma[0]=1;
        rep(i,n) {
            s+=v[i]; 
            if(ma.find(s-k)!=ma.end()) c+=ma[s-k];
            ma[s]++;
        }
        return c;
    }
};
