class Solution {
public:
    string finalString(string s) {
        string ans = "";   
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(s[i] != 'i')
            {
                ans +=s[i];
            }
            else{
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
    }
};