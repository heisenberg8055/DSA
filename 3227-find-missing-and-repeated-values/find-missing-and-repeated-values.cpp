class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans(2);
        int n = grid.size();
        vector<bool>vis((n * n) + 1 , false);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int idx = grid[i][j];
                if (vis[idx]) {
                    ans[0] = idx;
                }
                vis[idx] = true;
            }
        }
        for(int i = 1; i <= n * n; i++) {
            if (!vis[i]) {
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};