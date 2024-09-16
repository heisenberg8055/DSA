class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string temp = "";
        int sz = 0;
        for(int i = 0; i < n; i++)
        {
            if(isalnum(s[i]))
            {
                temp.push_back(tolower(s[i]));
                sz++;
            }
        }
        int l = 0, r = sz - 1;
        while(l <= r)
        {
            if(temp[l] == temp[r])
            {
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};