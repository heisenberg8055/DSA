class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size() - 1;
        int o = 0, c = 0;
        for(int i = 0; i <= n; i++)
        {
            if(s[i] == '(' || s[i] == '*'){
                o++;
            }
            else{
                o--;
            }
            if(s[n - i] == ')' || s[n - i] == '*')
            {
                c++;
            }
            else{
                c--;
            }
            if(o < 0 || c < 0)
            {
                return false;
            }
        }
        return true;
    }
};