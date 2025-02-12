class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(1, 1);
        if (rowIndex == 0) {
            return ans;
        }
        for(int i = 1; i <= rowIndex; i++) {
            vector<int>reff(i + 1, 1);
            for(int j = 1; j < i; j++) {
                reff[j] = ans[j - 1] + ans[j];
            }
            ans = reff;
        }
        return ans;
    }
};