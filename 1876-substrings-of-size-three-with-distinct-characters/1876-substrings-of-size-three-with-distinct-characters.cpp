class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        unordered_map<char,int>mp;
        int i = 0, j = 0;
        while(j < n)
        {
            if(j - i < 3)
            {
                mp[s[j]]++;
                j++;
            }
            else{
                if(mp.size() == 3)
                {
                    ans++;
                }
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        if(mp.size() == 3)
        {
            ans++;
        }
        return ans;
    }
};