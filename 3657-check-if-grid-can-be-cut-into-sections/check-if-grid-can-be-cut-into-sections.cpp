class Solution {
private:
    vector<vector<int>> help(vector<vector<int>>& reff) {
        vector<vector<int>> ans;
        sort(reff.begin(), reff.end());
        int n = reff.size();
        ans.push_back(reff[0]);
        for(int i = 1; i < n; i++) {
            if(ans.back()[1] <= reff[i][0]){
                ans.push_back(reff[i]);
                continue;
            }
            ans.back()[1] = max(ans.back()[1], reff[i][1]);
        }
        return ans;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m = rectangles.size();
        vector<vector<int>>x;
        vector<vector<int>>y;
        for(int i = 0; i < m; i++) {
            x.push_back({rectangles[i][0], rectangles[i][2]});
            y.push_back({rectangles[i][1], rectangles[i][3]});
        }
        return help(x).size() > 2 ? true : help(y).size() > 2 ? true : false;
    }
};