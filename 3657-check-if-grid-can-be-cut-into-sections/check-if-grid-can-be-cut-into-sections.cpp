class Solution {
private:
    vector<vector<int>> help(vector<vector<int>>& reff) {
        vector<vector<int>> ans;
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
        sort(x.begin(), x.end());
        x = help(x);
        int xs = x.size(), cnt = 1;
        for(int i = 1; i < xs; i++) {
            if(x[i - 1][1] <= x[i][0]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            if(cnt == 3) {
                return true;
            }
        }
        sort(y.begin(), y.end());
        y = help(y);
        int ys = y.size(), cnty = 1;
        for(int i = 1; i < ys; i++) {
            if(y[i - 1][1] <= y[i][0]) {
                cnty++;
            }
            else {
                cnty = 1;
            }
            if(cnty == 3) {
                return true;
            }
        }
        return false;
    }
};