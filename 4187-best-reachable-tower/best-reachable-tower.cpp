class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int maxi = INT_MIN;
        vector<int>ans(2, -1);
        sort(towers.begin(), towers.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[2] == b[2]) {
                if(a[0] == b[0]) {
                    return a[1] < b[1];
                } else {
                    return a[0] < b[0];
                }
            }
            return a[2] > b[2];
        });
        int x = center[0];
        int y = center[1];
        for(auto &it: towers) {
            int dist = abs(x - it[0]) + abs(y - it[1]);
            if(dist <= radius) {
                if(maxi < it[2]) {
                    maxi = it[2];
                    ans[0] = it[0];
                    ans[1] = it[1];
                }
            }
       }
       return ans;
    }
};