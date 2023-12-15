class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_set<string>s;
        for(int i = 0; i < n; i++)
        {
            s.insert(paths[i][1]);
        }
        for(int i = 0; i < n; i++)
        {
            s.erase(paths[i][0]);
        }
        return *s.begin();
    }
};