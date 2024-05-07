class Solution {
private:
    bool vowel(char x) 
    { 
        if (x == 'a' || x == 'e' || x == 'i' ||  
            x == 'o' || x == 'u' || x == 'A' ||  
            x == 'E' || x == 'I' || x == 'O' || x == 'U') 
            return true;
        else
            return false; 
    }
    bool consonant(char x) 
    { 
        if ((x != 'a' && x != 'e' && x != 'i' &&  
            x != 'o' && x != 'u' && x != 'A' &&  
            x != 'E' && x != 'I' && x != 'O' && x != 'U') && isdigit(x) == false) 
            return true;
        else
            return false; 
    }
public:
    bool isValid(string word) {
        bool v = false, c = false;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(word[i] == '@' || word[i] == '#' || word[i] == '$')
            {
                return false;
            }
            v == false ? v = vowel(word[i]) : v;
            c == false ? c = consonant(word[i]) : c;
        }
        return n > 2 && v && c;
    }
};