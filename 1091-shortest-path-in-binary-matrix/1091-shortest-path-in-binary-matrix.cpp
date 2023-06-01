class Solution {
private:
    bool isValid(int sr,int sc,vector<vector<int>> & grid, int n)
    {
        if(sr>=0 && sc>=0 && sr<n && sc<n && grid[sr][sc]==0)
        {
            return true;
        }
        return false;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        q.push({1,{0,0}});
        int ans=-1;
        while(q.empty()==false)
        {
            int steps=q.front().first;
            int sr=q.front().second.first;
            int sc=q.front().second.second;
            q.pop();
            if(!isValid(sr,sc,grid,n))
            {
                continue;
            }
            if(ans)
            {
                ans=max(ans,steps);
            }
            if(sr==n-1 && sc==n-1)
            {
                return ans;
            }
            grid[sr][sc]=1;
            steps+=1;
            q.push({steps,{sr-1,sc-1}});
            q.push({steps,{sr-1,sc}});
            q.push({steps,{sr-1,sc+1}});
            q.push({steps,{sr,sc-1}});
            q.push({steps,{sr,sc+1}});
            q.push({steps,{sr+1,sc-1}});
            q.push({steps,{sr+1,sc}});
            q.push({steps,{sr+1,sc+1}});
        }
        return -1;
    }
};