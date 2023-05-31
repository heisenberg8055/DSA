class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                unordered_set<int>u;
                unordered_set<int>d;
                int x = i-1;
                int y = j-1;
                while(x>=0 && y>=0)
                {
                    u.insert(grid[x--][y--]);
                }
                x = i+1;
                y = j+1;
                while(x<m && y<n)
                {
                    d.insert(grid[x++][y++]);
                }
                ans[i][j] = abs(int(u.size()-d.size()));
             }
        }
        return ans;
    }
};