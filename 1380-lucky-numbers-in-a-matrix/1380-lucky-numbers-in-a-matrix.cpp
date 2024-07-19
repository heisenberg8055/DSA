class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>mini(m, INT_MAX);
        vector<int>maxi(n, INT_MIN);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mini[i] = min(mini[i], matrix[i][j]);
                maxi[j] = max(maxi[j], matrix[i][j]);
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mini[i] == maxi[j])
                {
                    ans.push_back(mini[i]);
                }
            }
        }
        return ans;
    }
};