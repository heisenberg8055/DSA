class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1, mp[82] = {};
        for(int n: nums) {
            int sum = 0, reff = n;
            while(reff) {
                int temp = reff % 10;
                sum += temp;
                reff /= 10;
            }
            if (mp[sum]) {
                ans = max(ans, mp[sum] + n);
            }
            mp[sum] = max(mp[sum], n);
        }
        return ans;
    }
};