class Solution {
private:
    bool isVowel(char c)
    {
       return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
public:
    string sortVowels(string s) {
        multiset<char>st;
        for(auto it:s)
        {
            if(isVowel(it))
            {
                st.insert(it);
            }
        }
        auto it = st.begin();
        for(int i = 0; i < s.size(); i++)
        {
            if(isVowel(s[i]))
            {
                s[i] = *it;
                it++;
            }
        }
        return s;
    }
};