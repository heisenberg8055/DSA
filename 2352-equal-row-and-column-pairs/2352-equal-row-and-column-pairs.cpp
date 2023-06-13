class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        map<vector<int>, int>mp;
        for(auto it:grid)
        {
            mp[it]++;
        }
        for(int i = 0;i<n;i++)
        {
            vector<int>temp;
            for(int j = 0;j<n;j++)
            {
                temp.push_back(grid[j][i]);
            }
            if(mp.find(temp) != mp.end())
            {
                ans += mp[temp];
            }
        }
        return ans;
    }
};