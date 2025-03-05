class Solution {
int maxi = 0;
private:
    void help(vector<bool>& vis, vector<vector<int>>& s, vector<vector<int>>& m, int pos, int score) {
        if (pos >= s.size()) {
            maxi = max(maxi, score);
            return;
        }
        for(int i = 0; i < m.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                help(vis, s, m, pos + 1, score + scor(s[pos], m[i]));
                vis[i] = false;
            }
        }
    }
    int scor(vector<int>& a,vector<int>& b) {
        int ans = 0;
        for(int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) {
                ans++;
            }
        }
        return ans;
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        vector<bool>vis(m, false);
        help(vis, students, mentors, 0, 0);
        return maxi;
    }
};