class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int l = 0, r = 0, cnt = 0;
        while(r < n) {
            if(nums[r] == maxi) {
                cnt++;
            }
            while(cnt >= k) {
                if(nums[l] == maxi) {
                    cnt--;
                }
                l++;
                ans += n - r;
            }
            r++;
        }
        return ans;
    }
};