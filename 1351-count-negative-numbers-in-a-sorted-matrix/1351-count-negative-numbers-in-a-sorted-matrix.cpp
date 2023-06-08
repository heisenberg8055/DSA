class Solution {
private:
    void bs(vector<int>& grid, int& ans)
    {
        int i = 0, j = grid.size()-1;
        while(i<j)
        {
            int mid = (i + j) /2;
            if(grid[mid]>=0)
            {
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        grid[j]<0 ? ans += grid.size() - j: ans+=0;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++)
        {
            bs(grid[i],ans);
        }
        return ans;
    }
};