class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int k = unordered_set<int>(nums.begin(), nums.end()).size();
        int i = 0;
        int ans = 0;
        unordered_map<int, int> count;
        for(int j = 0; j < n; j++) {
            k -= count[nums[j]]++ == 0;
            while(k == 0) {
                k += --count[nums[i++]] == 0;
            }
            ans += i;
        }
        return ans;
    }
};