class Solution {
private:
    vector<vector<int>> help(vector<vector<int>>& reff) {
        vector<vector<int>>ans;
        int n = reff.size();
        sort(reff.begin(), reff.end());
        ans.push_back(reff[0]);
        for(int i = 1; i < n; i++) {
            if(ans.back()[1] < reff[i][0]) {
                ans.push_back(reff[i]);
                continue;
            }
            ans.back()[1] = max(ans.back()[1], reff[i][1]);
        }
        return ans;
    }
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        vector<vector<int>> reff = help(meetings);
        for(auto it: reff) {
            days -= (it[1] - it[0] + 1);
        }
        return days;
    }
};