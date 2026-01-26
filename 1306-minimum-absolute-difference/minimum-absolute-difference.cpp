class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int n = arr.size();
        map<int, vector<pair<int, int>>>mp;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < n; i++) {
            mp[arr[i] - arr[i - 1]].push_back({arr[i - 1], arr[i]});
        }
        for(auto it: mp) {
            for(auto x: it.second) {
                ans.push_back({x.first, x.second});
            }
            break;
        }
        return ans;
    }
};