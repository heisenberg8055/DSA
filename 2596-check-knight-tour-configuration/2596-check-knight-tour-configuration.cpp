class Solution {
private:
    int n;
    bool isValid(int x, int y,vector<vector<int>>& grid,int cnt)
    {
        if(x>=0 && x<n && y>=0 && y<n && grid[x][y] == cnt)
        {
            return true;
        }
        return false;
    }
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        n = grid.size();
        int dx[] = {-2,-1,1,2,2,1,-1,-2};
        int dy[] = {1,2,2,1,-1,-2,-2,-1};
        int x = 0;
        int y = 0;
        int cnt = 1;
        while(cnt<n*n)
        {
            bool cng = 0;
            for(int i = 0;i<8;i++)
            {
                int fx = x + dx[i];
                int fy = y + dy[i];
                if(isValid(fx,fy,grid,cnt))
                {
                    x = fx;
                    y = fy;
                    cnt++;
                    cng = 1;
                    break;
                }
            }
            if(cng == 0)
            {
                return false;
            }
        }
        return true;
    }
};