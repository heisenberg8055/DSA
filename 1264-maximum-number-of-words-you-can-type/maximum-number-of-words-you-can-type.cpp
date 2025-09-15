class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 1, cnt = 0;
        unordered_set<char>s;
        for(int i = 0; i < brokenLetters.size(); i++) {
            s.insert(brokenLetters[i]);
        }
        bool pro = 0;
        for(int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                pro = 0;
                ans++;
                continue;
            }
            if (pro) {
                continue;
            }
            if (s.find(text[i]) != s.end()) {
                cnt++;
                pro = 1;
                continue;
            }
        }
        return ans - cnt;
    }
};