class Solution {
private:
    int trav(int ind, vector<int> &nums, vector<int> &dp, int f)
    {
        if(f && ind >= nums.size()-1)
        {
            return 0;
        }
        if(f == 0 && ind >=nums.size())
        {
            return 0;
        }
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        int pick = nums[ind] + trav(ind + 2, nums, dp, f);
        int np = trav(ind + 1, nums, dp, f);
        return dp[ind] = max(pick, np);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        vector<int>dp(n, -1);
        vector<int>dp1(n, -1);
        int v1 = trav(0, nums, dp, 1);
        int v2 = trav(1, nums, dp1, 0);
        cout<<v1<<" "<<v2;
        return max(v1, v2);
    }
};