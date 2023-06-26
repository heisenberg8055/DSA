class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        unordered_map<string,int>mp;
        for(auto it:words)
        {
            mp[it]++;
        }
        for(int i = 0;i<n;i++)
        {
            string it = words[i];
            reverse(it.begin(),it.end());
            if(it == words[i]){
                if(mp[it]>1)
                {
                    mp[it]-=2;
                }
            }
            else if(mp[words[i]] && mp[it])
            {
                ans++;
                mp[words[i]]--;
                mp[it]--;
            }
        }
        return ans;
    }
};