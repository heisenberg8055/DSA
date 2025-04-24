class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int ans = 0;
        string temp = "";
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                temp += '1';
            } else {
                temp += '0';
            }
        }
        bool chk = false;
        int j = 0;
        for(int i = 0; i < n - 1; i++) {
            if(chk && temp[i] == '1') {
                while (temp[j++] != '1') {
                    
                }
            }
            if (temp[i] == '1') {
                chk = true;
            }
            ans = max(ans, i - j + 1);
        }
        return ans + 1;
    }
};