class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n1 = word1.size();
        int n2 = word2.size();
        int i = 0, j = 0;
        while (true) {
            if (i < n1) {
                ans += word1[i++];
            } else {
                ans += word2.substr(j, string::npos);
                break;
            }
            if (j < n2) {
                ans += word2[j++];
            } else {
                ans += word1.substr(i, string::npos);
                break;
            }
        }
        return ans;
    }
};