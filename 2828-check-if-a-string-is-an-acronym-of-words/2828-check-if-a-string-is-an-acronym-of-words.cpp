class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string temp = "";
        for(auto it:words)
        {
            temp+=it[0];
        }
        return temp == s;
    }
};