class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+2];
        memset(dp, 0, sizeof(dp));
        dp[n] = 0, dp[n+1] = 0;
        for(int i = n-1; i >= 0; i--)
        {
            dp[i] = cost[i] + min(dp[i+1] , dp[i+2]);
        }
        return dp[0] > dp[1] ? dp[1] : dp[0];
    }
};