class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_set<string>s;
        unordered_set<string>e;
        for(int i = 0; i < n; i++)
        {
            s.insert(paths[i][0]);
            e.erase(paths[i][0]);
            e.insert(paths[i][1]);
        }
        for(auto it: s)
        {
            e.erase(it);
        }
        return *e.begin();
    }
};