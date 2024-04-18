class Solution {
private:
    bool isValid(int x, int y, int m, int n)
    {
        return x < m && y < n && x >= 0 && y >= 0;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    int count = 0;
                    for(int k = 0; k < 4; k++)
                    {
                        if(isValid(i + dx[k], j + dy[k], m, n) && grid[i + dx[k]][j + dy[k]])
                        {
                            count++;
                        }
                    }
                    ans += 4 - count;
                }
            }
        }
        return ans;
    }
};