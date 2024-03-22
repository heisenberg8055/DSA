class Solution {
private:
    int calc(int i, int j, vector<vector<int>> &dp, int arr[], int k)
    {
        if(abs(arr[i] - arr[j]) <= k || i == j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        return dp[i][j] = min(arr[i] + calc(i+1, j, dp, arr, k), arr[j] - arr[i] - k + calc(i, j - 1, dp, arr, k));
    }
public:
    int minimumDeletions(string word, int k) {
        vector<vector<int>>dp(26, vector<int>(26, -1));
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for(auto &it: word)
        {
            arr[it - 97]++;
        }
        sort(arr, arr + 26);
        return calc(0, 25, dp, arr, k);
    }
};