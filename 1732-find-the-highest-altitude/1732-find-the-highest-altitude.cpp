class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = INT_MIN;
        int att = 0;
        for(auto it:gain)
        {
            ans = max(att, ans);
            att += it;
        }
        ans = max(att, ans);
        return ans;
    }
};