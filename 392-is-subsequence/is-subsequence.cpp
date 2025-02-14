class Solution {
private:
    int isLCS(string s, string t, int i, int j, vector<vector<int>> &dp) {
        if (i == 0 || j == 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i - 1] == t[j - 1]) {
            return dp[i][j] = 1 + isLCS(s, t, i - 1, j - 1, dp);
        }
        return dp[i][j] = isLCS(s, t, i, j - 1, dp);
    }
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n > m) {
            return false;
        }
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
        return isLCS(s, t, n, m, dp) == n;
    }
};