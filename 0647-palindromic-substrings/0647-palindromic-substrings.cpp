class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            ans++;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i] ==  s[i+1])
            {
                ans++;
                dp[i][i+1]=1;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j = i+k-1;
                if(dp[i+1][j-1]==1 && s[i]==s[j])
                {
                    dp[i][j]=1;
                    ans++;
                }
            }
        }
        return ans;
    }
};