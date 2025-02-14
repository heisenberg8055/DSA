class Solution {
private:
    int help(int i, int n, vector<int>& cost, vector<int>& dp) {
        if (i > n - 1) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        return dp[i] = cost[i] + min(help(i + 1, n, cost, dp), help(i + 2, n, cost, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n, -1);
        return min(help(0, n, cost, dp), help(1, n, cost, dp));
    }
};