class Solution {
private:
    int help(vector<int>& reff, int comp, int x) {
        int ans = 0;
        for(auto it: reff){
            ans += abs(it - comp) / x;
        }
        return ans;
    }
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int>reff;
        int rem = grid[0][0] % x;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int comp = grid[i][j] % x;
                if (comp != rem) {
                    return -1;
                }
                reff.push_back(grid[i][j]);
            }
        }
        sort(reff.begin(), reff.end());
        int comp = reff.size() / 2;
        int calc = reff[comp];
        ans = max(ans, help(reff, calc, x));
        if(comp != 0 && comp % 2 == 0) {
            ans = min(ans, help(reff, reff[comp - 1], x));
        }
        return ans;
    }
};