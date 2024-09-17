class Solution {
private:
    unordered_map<string, int> help(string s)
    {
        unordered_map<string, int>mp;
        string x;
        stringstream ss(s);
        while(getline(ss, x, ' '))
        {
            mp[x]++;
        }
        return  mp;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        unordered_map<string, int>mp1 = help(s1);
        unordered_map<string, int>mp2 = help(s2);
        for(auto it: mp1)
        {
            if(it.second == 1)
            {
                if(mp2.find(it.first) == mp2.end())
                {
                    ans.push_back(it.first);
                }
            }
        }
        for(auto it: mp2)
        {
            if(it.second == 1)
            {
                if(mp1.find(it.first) == mp1.end())
                {
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};