class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans(m, vector<int>(n));
        vector<int>row(m);
        vector<int>col(n);
        for(int i = 0; i < n;i++)
        {
            int c = 0;
            for(int j = 0; j < m; j++)
            {
                if(grid[j][i] == 1){
                    c++;
                }
            }
            col[i] = c;
        }
        for(int i = 0; i < m;i++)
        {
            int c = 0;
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1){
                    c++;
                }
            }
            row[i] = c;
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans[i][j] = row[i] + col[j] - (m - row[i]) - (n - col[j]);
            }
        }
        return ans;
    }
};