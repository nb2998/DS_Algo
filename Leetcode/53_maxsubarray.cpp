class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int curr_max = nums[0];
        int glob_max = nums[0];
        for(int i=1;i<n;++i)
        {
            curr_max = max(curr_max+nums[i],nums[i]);
            glob_max = max(glob_max,curr_max);
        }
        return glob_max;
        
    }
};