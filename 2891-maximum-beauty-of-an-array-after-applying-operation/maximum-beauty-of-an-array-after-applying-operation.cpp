class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int l = 0, r = 0;
        sort(nums.begin(), nums.end());
        while(r < n) {
            if(nums[r] - nums[l] <= 2 * k) {
                ans = max(ans, r - l + 1);
                r++;
            } else {
                l++;
            }
        }        
        return ans;
    }
};