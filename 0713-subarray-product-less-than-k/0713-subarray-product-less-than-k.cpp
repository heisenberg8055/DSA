class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1)
        {
            return 0;
        }
        int ans = 0;
        int pro = 1;
        for(int l = 0, r = 0; r < n; r++)
        {
            pro *= nums[r];
            while(pro >= k)
            {
                pro/=nums[l++];
            }
            ans += r - l + 1;
        }
        return ans;
    }
};