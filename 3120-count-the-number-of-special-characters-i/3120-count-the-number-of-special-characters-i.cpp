class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        unordered_set<char>vis;
        for(auto it: word)
        {
            vis.insert(it);
        }
        for(int i = 0; i < 26; i++)
        {
            if(vis.find(65 + i) != vis.end() && vis.find(97 + i) != vis.end())
            {
                ans++;
            }
        }
        return ans;
    }
};