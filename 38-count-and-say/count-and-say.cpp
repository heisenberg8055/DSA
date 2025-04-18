class Solution {
private:
    string convert(string s) {
        string ans = "";
        int cnt = 0;
        char reff = s[0];
        int n = s.size(), i = 0;
        while(i < n) {
            if(reff == s[i]) {
                cnt++;
                i++;
            } else {
                string temp = to_string(cnt) + reff;
                ans += temp;
                reff = s[i];
                cnt = 0;
            }
        }
        string temp = to_string(cnt) + reff;
        ans += temp;
        return ans;
    }
public:
    string countAndSay(int n) {
        string ans = "1";
        while(--n){
            ans = convert(ans);
        }
        return ans;
    }
};