// Famous Interview Question to take out Median of Two Sorted Arrays in logarithmic time..
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size();
        int y = nums2.size();
        if(y<x) return findMedianSortedArrays(nums2,nums1);
        int lo = 0;
        int hi = x;
        while(lo<=hi)
        {
            int partitionX = (lo+hi)/2;
            int partitionY = (x+y+1)/2 - partitionX;
            int xmin = (partitionX==0)?INT_MIN:nums1[partitionX-1];
            int xmax = (partitionX==x)?INT_MAX:nums1[partitionX];
            
            int ymin = (partitionY==0)?INT_MIN:nums2[partitionY-1];
            int ymax = (partitionY==y)?INT_MAX:nums2[partitionY];
            
            if(xmin<=ymax && ymin<=xmax)
            {
                if((x+y)%2 == 0)
                {
                    int l = max(xmin,ymin);
                    int r = min(xmax,ymax);
                    double ans = (l+r);
                    ans/=2;
                    return ans;
                }
                else return max(xmin,ymin);
            }
            else if(xmin > ymax) hi = partitionX - 1;
            else lo = partitionX + 1;
        }
        return 0;
        
    }
};
// Driver Code
int main()
{
	// n = size of first array
	// m = size of second array
	int n,m;
	cin>>n>>m;
	vector<int> arr1(n),arr2(m);
	for(int i=0;i<n;++i) cin>>arr1[i];
	for(int i=0;i<m;++i) cin>>arr2[i];
	Solution* obj = new Solution();
	cout<<obj->findMedianSortedArrays(arr1,arr2)<<endl;
}
