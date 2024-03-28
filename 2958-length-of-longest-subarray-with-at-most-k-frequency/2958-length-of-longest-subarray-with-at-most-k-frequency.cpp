class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int>mp;
        int n = nums.size();
        for(int i = 0, j = 0; i < n; i++)
        {
            mp[nums[i]]++;
            while(mp[nums[i]] > k)
            {
                mp[nums[j++]]--;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};