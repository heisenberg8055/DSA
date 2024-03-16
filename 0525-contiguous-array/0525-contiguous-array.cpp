class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        mp.insert({0, -1});
        for(int i = 0; i < n; i++)
        {
            cnt += nums[i] == 1 ? 1 : -1;
            if(mp.find(cnt) != mp.end())
            {
                ans = max(ans, i - mp[cnt]);
            }
            else{
                mp.insert({cnt, i});
            }
        }
        return ans;
    }
};