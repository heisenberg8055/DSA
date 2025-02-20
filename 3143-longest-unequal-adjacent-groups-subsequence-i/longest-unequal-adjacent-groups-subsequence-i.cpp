class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string>ans;
        int comp = !groups[0];
        for(int i = 0; i < n; i++) {
            if(comp != groups[i]) {
                ans.push_back(words[i]);
                comp = !comp;
            }
        }
        return ans;
    }
};