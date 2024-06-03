class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans = 0;
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        while(j < m)
        {
            if(i >= n)
            {
                ans += m - j;
                return ans;
            }
            while(i < n && s[i] != t[j])
            {
                i++;
            }
            if(i < n && s[i] == t[j])
            {
                i++;
                j++;
            }
        }
        return ans;
    }
};