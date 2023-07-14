class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map<int,int>mp;
        for(auto it:arr)
        {
            int prev = mp.count(it - difference) ? mp[it - difference] : 0;
            mp[it] = prev + 1;
            ans = max(ans, mp[it]);
        }
        return ans;
    }
};