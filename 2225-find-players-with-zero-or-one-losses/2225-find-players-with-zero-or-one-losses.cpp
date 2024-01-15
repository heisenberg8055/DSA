class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2,vector<int>(0));
        int n=matches.size();
        map<int,int>mp;
        set<int>s;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            s.insert(matches[i][0]);
            s.insert(matches[i][1]);
            mp[matches[i][1]]++;    
        }
        for(auto it:s)
        {
            if(mp.find(it)==mp.end())
            {
                ans[0].push_back(it);
            }
        }
        for(auto it:mp)
        {
            if(it.second==1)
            {
                ans[1].push_back(it.first);
            }
        }
        return ans;
    }
};