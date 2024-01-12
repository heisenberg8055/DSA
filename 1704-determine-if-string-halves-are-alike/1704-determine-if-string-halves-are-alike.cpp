class Solution {
private:
    bool isVowel(char c)
    {
        return c == 'A'|| c == 'E'||c == 'I'||c == 'O'||c == 'U'||c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u';
    }
public:
    bool halvesAreAlike(string s) {
        int c1 = 0, c2 = 0;
        int n = s.size();
        for(int i = 0; i < n/2; i++)
        {
            if(isVowel(s[i]))
            {
                c1++;
            }
        }
        for(int i = n/2; i < n; i++)
        {
            if(isVowel(s[i]))
            {
                c2++;
            }
        }
        return c1 == c2;
    }
};