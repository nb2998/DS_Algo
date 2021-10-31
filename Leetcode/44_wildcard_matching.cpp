class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector< vector<bool> > dp(n+1, vector<bool>(m+1));
        dp[0][0] = true;
        for(int i=1;i<=m;++i)
        {
            if(p[i-1]=='*') dp[0][i] = dp[0][i] || dp[0][i-1];
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                int ii = i-1;
                int jj = j-1;
                if(p[jj] == '?' || s[ii] == p[jj]) dp[i][j] = dp[i][j] || dp[i-1][j-1];
                else if(p[jj] == '*')
                {
                    dp[i][j] = dp[i][j] || dp[i-1][j] || dp[i][j-1];
                }
                
            }
        }
        return dp[n][m];
        
    }
};