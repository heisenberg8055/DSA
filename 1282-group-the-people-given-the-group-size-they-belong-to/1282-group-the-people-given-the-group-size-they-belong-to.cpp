class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        int n = groupSizes.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0 ; i < n; i++)
        {
            int reff = groupSizes[i];
            if(mp.find(reff) != mp.end())
            {
                auto it = mp[reff];
                if(it.size() == reff)
                {
                    ans.push_back(it);
                    mp.erase(reff);
                }
            }
            mp[reff].push_back(i);
        }
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};