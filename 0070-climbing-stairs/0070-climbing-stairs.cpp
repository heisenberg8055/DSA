class Solution {
private:
    int trav(int n, int dp[])
    {
        if(n<0)
        {
            return 0;
        }
        if(n == 0 || n == 1)
        {
            return dp[n] = 1;
        }
        if(dp[n])
        {
            return dp[n];
        }
        return dp[n] = trav(n-1, dp) + trav(n-2, dp);
    }
public:
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        trav(n,dp);
        return dp[n];
    }
};