class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int mini = min(nums[i], nums[j]);
                int diff = abs(nums[i] -  nums[j]);
                if(diff <= mini)
                {
                    ans = max(ans, nums[i] ^ nums[j]);
                }
            }
        }
        return ans;
    }
};