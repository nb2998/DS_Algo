//https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        int left = 0;
        int right = n-1;
        int ans = 0;
        int left_max, right_max;
        left_max = right_max = 0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                if(height[left] >= left_max) left_max = height[left];
                else ans += left_max - height[left];
                ++left;
            }
            else
            {
                if(height[right] >= right_max)  right_max = height[right];
                else ans += right_max - height[right];
                --right;
            }
        }
        return ans;
        
    }
};