class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        vector<int>temp(heights.begin(), heights.end());
        sort(temp.begin(), temp.end());
        int n = heights.size();
        for(int i = 0; i < n; i++)
        {
            if(heights[i] != temp[i])
            {
                ans++;
            }
        }
        return ans;
    }
};