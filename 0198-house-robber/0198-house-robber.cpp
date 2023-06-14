class Solution {
private:
    int trav(int ind, vector<int> &nums, vector<int> &dp)
    {
        if(ind>=nums.size())
        {
            return 0;
        }
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        int pick = nums[ind] + trav(ind+2, nums, dp);
        int np = trav(ind+1, nums, dp);
        return dp[ind] = max(pick, np);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return trav(0, nums, dp);
    }
};