class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        stack<pair<int, int>>st;
        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push({colors[i], neededTime[i]});
            } else if (st.top().first == colors[i]) {
                auto temp = st.top();
                st.pop();
                ans += min(temp.second, neededTime[i]);
                st.push({colors[i], max(temp.second, neededTime[i])});
            } else {
                st.push({colors[i], neededTime[i]});
            }
        }
        return ans;
    }
};