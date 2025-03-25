class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        ans.push_back(intervals[0]);
        for(int i = 1; i < n; i++) {
            if(ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
                continue;
            }
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        return ans;
    }
};