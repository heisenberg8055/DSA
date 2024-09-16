class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0;
        int n = s.size();
        if(n == 1)
        {
            return 1;
        }
        int i = 0;
        while(i < n)
        {
            int cnt = 1;
            char c = s[i++];
            while(i < n && s[i] - c == 1)
            {
                cnt++;
                c = s[i++];
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};