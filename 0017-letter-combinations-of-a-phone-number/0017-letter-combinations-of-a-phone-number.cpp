class Solution {
public:
    string reff;
    unordered_map<int, vector<char>>mp;
    vector<string>ans;
    void trav(int i, string temp)
    {
        vector<char>a = mp[reff[i]-'0'];
        for(auto it:a)
        {
            if(i==reff.size()-1)
            {
                ans.push_back(temp+it);
            }
            else
            {
                trav(i+1, temp+it);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        reff=digits;
        if(digits.size()==0)
        {
            return {};
        }
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
        trav(0, "");
        return ans;
    }
};