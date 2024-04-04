class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int n = s.size();
        int lc = 0, rc = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                lc++;
                ans = max(ans, lc - rc);
            }
            else if(s[i] == ')')
            {
                rc++;
                ans = max(ans, lc - rc);
            }
            else
            {
                ans = max(ans, lc - rc);
            }
        }
        return ans;
    }
};