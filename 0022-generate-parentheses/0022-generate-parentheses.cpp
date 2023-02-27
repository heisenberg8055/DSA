class Solution {
private:
    void help(vector<string>& ans,int o, int c, string s,int n)
    {
        if(o == n && c == n)
        {
            ans.push_back(s);
            return;
        }
        if(o<n)
        {
            help(ans,o+1,c,s+"(",n);
        }
        if(c<o)
        {        
            help(ans,o,c+1,s+")",n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        help(ans,0,0,"",n);
        return ans;
    }
};