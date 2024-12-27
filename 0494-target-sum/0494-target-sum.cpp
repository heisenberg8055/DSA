class Solution {
private:
    int help(vector<int>& nums, int n, int target, int calc, int i)
    {
        int ans = 0;
        if(i == n)
        {
            if(target == calc)
            {
                return 1;
            }
            else{
                return 0;
            }
        }
        ans += help(nums, n, target, calc + nums[i], i+1);
        ans += help(nums, n, target, calc - nums[i], i+1);
        return ans;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return help(nums, n, target, 0, 0);
    }
};