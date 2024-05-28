class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int n = s.size();
        int st = 0;
        int curr = 0;
        for(int i = 0; i < n; i++)
        {
            curr += abs(s[i] - t[i]);
            while(curr > maxCost)
            {
                curr -= abs(s[st] - t[st]);
                st++;
            }
            ans = max(ans, i - st + 1);
        }
        return ans;
    }
};