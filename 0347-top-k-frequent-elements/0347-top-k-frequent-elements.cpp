class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>q;
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            q.push({it.second,it.first});
        }
        for(int i = 0;i<k;i++)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};