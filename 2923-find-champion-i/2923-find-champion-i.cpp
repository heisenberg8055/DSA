class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>reff(n, 0);
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(i != j)
                {
                    if(grid[i][j] == 1)
                    {
                        reff[i]++;
                    }
                    else{
                        reff[j]++;
                    }
                }
            }
        }
        return max_element(reff.begin(),reff.end()) - reff.begin();
    }
};