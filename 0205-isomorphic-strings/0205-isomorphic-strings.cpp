class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char>mp;
        unordered_map<char,char>mp1;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) == mp.end())
            {
                mp.insert({s[i], t[i]});
            }
            else{
                if(mp[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(mp1.find(t[i]) == mp1.end())
            {
                mp1.insert({t[i], s[i]});
            }
            else{
                if(mp1[t[i]]!= s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};