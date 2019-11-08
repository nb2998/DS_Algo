#include<bits/stdc++.h>
using namespace std;
struct Building
{
    int x,y,se; // se is 0 means start, 1 means end
    Building(){ }
    Building(int a, int b, int c)
    {
        x = a;
        y = b;
        se = c;
    }
};
bool compare(Building a, Building b)
{
    if(a.x == b.x && a.se == 0 && b.se == 0) return a.y > b.y; // edge case 1
    if(a.x == b.x && a.se == 1 && b.se == 1) return a.y < b.y; //edge case 2
    if(a.x == b.x && (a.se != b.se)) return a.se < b.se; // edge case 3
    return a.x < b.x;
}
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& arr) {
        vector< vector<int> > ans;
        int n = arr.size();
        if(n==0) return ans;
        vector<Building> bd;
        for(int i=0;i<n;++i)
        {
            int x1 = arr[i][0];
            int x2 = arr[i][1];
            int ht = arr[i][2];
            bd.push_back(Building(x1,ht,0));
            bd.push_back(Building(x2,ht,1));
        }
        sort(bd.begin(),bd.end(),compare);
        multiset<int> mp;
        mp.insert(0);
        for(int i=0;i<bd.size();++i)
        {
            int x = bd[i].x;
            int ht = bd[i].y;
            int se = bd[i].se;
            auto rit = mp.rbegin();
            int currMax = *rit;
            if(se==0)
            {
                mp.insert(ht);
                rit = mp.rbegin();
                if(*rit != currMax)
                {
                    vector<int> temp;
                    temp.push_back(x);
                    temp.push_back(*rit);
                    ans.push_back(temp);
                }
            }
            else
            {
                mp.erase(lower_bound(mp.begin(),mp.end(),ht));
                rit = mp.rbegin();
                if(*rit != currMax)
                {
                    vector<int> temp;
                    temp.push_back(x);
                    temp.push_back(*rit);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
        
    }
};
//Driver Code
int main()
{
	int n;
	cout<<"Enter number of points in space: "; // in the form [ Li, Ri, Hi ] where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height.
	cin>>n;
	vector< vector<int> > arr;
	for(int i=0;i<n;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		vector<int> temp = {x,y,z};
		arr.push_back(temp);
	}
	Solution *obj = new Solution();
	auto v = obj->getSkyline(arr);
	for(auto i:v)
	{
		for(auto j:i) cout<<j<<" ";
		cout<<endl;
	}
	
}
