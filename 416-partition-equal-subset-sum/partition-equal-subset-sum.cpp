class Solution {
private:
    bool help(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target == 0){
            return true;
        }
        if(i == 0) {
            return nums[0] == target;
        }
        if(dp[i][target] != -1) {
            return dp[i][target];
        }
        bool nT = help(i - 1, target, nums, dp);
        bool T = false;
        if (nums[i] <= target) {
            T = help(i - 1, target - nums[i], nums, dp);
        }
        return dp[i][target] = nT || T;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        return help(n - 1, target, nums, dp);
    }
};