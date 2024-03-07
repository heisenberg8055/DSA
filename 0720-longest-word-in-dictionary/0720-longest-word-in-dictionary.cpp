class Solution {
private:
    bool chk(string s, unordered_set<string> &st)
    {
        int n = s.size();
        for(int i = 1; i <= n; i++)
        {
            string temp = s.substr(0,i);
            if(st.find(temp) == st.end())
            {
                return false;
            }
        }
        return true;
    }
public:
    string longestWord(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&](string a, string b){
            if(a.size() == b.size())
            {
                return a < b;
            }
            else{
                return a.size() > b.size();
            };
        });
        unordered_set<string>s(words.begin(), words.end());
        for(int i = 0; i < n; i++)
        {
            if(chk(words[i],s))
            {
                return words[i];
            }
        }
        return "";
    }
};