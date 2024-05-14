class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int sr,int sc,int row,int col,int cost)
    {
        if(sr<0||sr>=row||sc<0||sc>=col||vis[sr][sc]==1||grid[sr][sc]==0)
        {
            ans=max(cost,ans);
            return;
        }
        cost+=grid[sr][sc];
        vis[sr][sc]=1;
        dfs(grid,vis,sr-1,sc,row,col,cost);
        dfs(grid,vis,sr+1,sc,row,col,cost);
        dfs(grid,vis,sr,sc-1,row,col,cost);
        dfs(grid,vis,sr,sc+1,row,col,cost);
        vis[sr][sc]=0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]!=0)
                {
                    dfs(grid,vis,i,j,r,c,0);
                }
            }
        }
        return ans;
    }
};