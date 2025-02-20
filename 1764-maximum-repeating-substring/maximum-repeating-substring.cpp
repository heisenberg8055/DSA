class Solution {
private:
    bool chk(int i, string word, string s) {
        string temp = "";
        while(i--) {
            temp += word;
        }
        if(temp.size() > s.size()) {
            return false;
        }
        for(int i = 0; i < s.size() - temp.length() + 1; i++) {
            if(temp == s.substr(i, temp.length())) {
                return true;
            }
        }
        return false;
    }
public:
    int maxRepeating(string s, string word) {
        int ans  = 0;
        int m = s.size(), n = word.size();
        if (n > m) {
            return ans;
        }
        while(chk(ans + 1, word, s)) {
            ans++;
        }
        return ans;
    }
};