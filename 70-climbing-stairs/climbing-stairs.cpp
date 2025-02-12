class Solution {
private:
    int trav(int n, vector<int> &dp) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = trav(n - 1, dp) + trav(n - 2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n + 1, -1);
        return trav(n, dp);
    }
};