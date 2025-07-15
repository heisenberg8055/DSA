class Solution {
private:
    bool isInside(char c) {
        if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123)) {
            return true;
        }
        return false;
    }

    bool isVowel(char temp) {
        if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' ||
            temp == 'u' || temp == 'A' || temp == 'E' || temp == 'I' ||
            temp == 'O' || temp == 'U') {
            return true;
        }
        return false;
    }

    bool isCon(char c) {
        if (isVowel(c) == false && isdigit(c) == false) {
            return true;
        }
        return false;
    }

public:
    bool isValid(string word) {
        int n = word.size();
        if(n < 3) {
            return false;
        }
        bool v = false, c = false;
        for (int i = 0; i < n; i++) {
            char temp = word[i];
            if (isInside(temp) == false) {
                return false;
            }
            if (isVowel(temp)) {
                v = true;
            }
            if (isCon(temp)) {
                c = true;
            }
        }
        return v && c;
    }
};