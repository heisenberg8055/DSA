class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev = matrix[0];
        for(int i = 1; i < n; i++) {
            vector<int>curr(n);
            for(int j = 0; j < n; j++) {
                int cl, cr, t;
                cl = cr = t = INT_MAX;
                if(j > 0) {
                    cl = prev[j - 1];
                }
                if(j < n - 1) {
                    cr = prev[j + 1];
                }
                t = prev[j];
                curr[j] = min(cl, min(cr, t)) + matrix[i][j];
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for(auto it: prev) {
            ans = min(ans, it);
        }
        return ans;
    }
};