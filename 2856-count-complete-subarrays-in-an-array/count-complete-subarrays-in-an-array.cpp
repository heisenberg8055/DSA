class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for(int i = 0; i < n; i++) {
            unordered_set<int>s;
            for(int j = i; j < n; j++) {
                s.insert(nums[j]);
                if(s.size() == mp.size()) {
                    ans += n - j;
                    break;
                }
            }
        }
        return ans;
    }
};