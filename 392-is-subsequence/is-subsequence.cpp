class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if(n > m) {
            return false;
        }
        int i = 0, j = 0;
        while(i < n && j < m) {
            while(j < m && t[j] != s[i]) {
                j++;
            }
            if(t[j] == s[i]){

            
            i++;
            j++;
            } else{
                break;
            }
        }
        return i == n;
    }
};