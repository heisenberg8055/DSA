class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>>mp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mp[i - j].push_back(grid[i][j]);
            }
        }
        for (auto& [a, b] : mp) {
            if (a < 0) 
                sort(b.begin(), b.end());
            else 
                sort(b.begin(), b.end(), greater<int>());
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                grid[i][j] = mp[i - j].front();
                mp[i - j].erase(mp[i - j].begin());
            }
        }
        return grid;
    }
};