class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector< vector<int> > dp(n, vector<int>(n));
        for(int i=0;i<n;++i) 
        {
            dp[i][i] = nums[i];
            if(i-1>=0) dp[i][i] *= nums[i-1];
            if(i+1<n) dp[i][i] *= nums[i+1];
        }
        for(int gap=1;gap<n;++gap)
        {
            for(int i=0;i<n;++i)
            {
                int j = i+gap;
                if(j>=n) break;
                int temp = INT_MIN;
                for(int k=i;k<=j;++k)
                {
                    int l,r,ls,rs;
                    l = r = 1;
                    ls = rs = 0;
                    if(i-1>=0) l = nums[i-1];
                    if(j+1 < n) r = nums[j+1];
                    if(k+1<=j) rs = dp[k+1][j];
                    if(k-1>=i) ls = dp[i][k-1];
                    temp = max(nums[k]*l*r + ls + rs, temp);
                }
                dp[i][j] = max(dp[i][j],temp);
            }
        }
        return dp[0][n-1];
        
    }
};