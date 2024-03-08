class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxfq = 0, ans = 0;
        unordered_map<int,int>mp;
        for(auto &it: nums)
        {
            mp[it]++;
            maxfq < mp[it] ? maxfq = mp[it] : 1;
        }
        for(auto &[a,b]: mp)
        {
            if(maxfq == b)
            {
                ans++;
            }
        }
        return maxfq * ans;
    }
};