class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        unordered_set<int>s;
        for(const auto &it: arr)
        {
            mp[it]++;
        }
        for(auto it: mp)
        {
            if(s.find(it.second) != s.end())
            {
                return false;
            }
            s.insert(it.second);
        }
        return true;
    }
};