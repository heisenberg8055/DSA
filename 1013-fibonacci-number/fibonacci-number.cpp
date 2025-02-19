class Solution {
    vector<int>dp;
private:
    int help(int n) {
        if (n < 2) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = fib(n - 1) + fib(n - 2);
    }
public:
    int fib(int n) {
        dp.resize(n + 1, -1);
        return help(n);
    }
};