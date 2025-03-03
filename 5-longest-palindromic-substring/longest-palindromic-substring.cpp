class Solution {
private:
    string expand(int i, int j, string s) {
        int left = i, right = j;
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
            string odd = expand(i, i, s);
            if(odd.size() > ans.size()) {
                ans = odd;
            }
            string even = expand(i, i + 1, s);
            if(even.size() > ans.size()) {
                ans = even;
            }
        }
        return ans;
    }
};