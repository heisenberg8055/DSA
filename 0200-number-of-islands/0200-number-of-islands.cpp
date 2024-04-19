class Solution {
private:
    bool isValid(int x, int y, int m, int n)
    {
        return x < m && y < n && y >= 0 && x >= 0;
    }
    void dfs(int i, int j, int m, int n, vector<vector<bool>>& vis, vector<vector<char>>& grid, int dx[], int dy[])
    {
        vis[i][j] = true;
        for(int t = 0; t < 4; t++)
        {
            int fx = i + dx[t];
            int fy = j + dy[t];
            if(isValid(fx, fy, m, n) && grid[fx][fy] == '1' && vis[fx][fy] == false)
            {
                dfs(fx, fy, m, n, vis, grid, dx, dy);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == false)
                {
                    dfs(i, j, m, n, vis, grid, dx, dy);
                    ans++;
                }
            }
        }
        return ans;
    }
};