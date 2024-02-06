class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n = strs.size();
        unordered_map<string,vector<int>>mp;
        for(int i = 0; i < n; i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }
        for(auto it:mp)
        {
            vector<int>temp = it.second;
            vector<string>reff;
            int n = temp.size();
            for(int i = 0; i < n; i++)
            {
                reff.push_back(strs[temp[i]]);
            }
            ans.push_back(reff);
        }
        return ans;
    }
};