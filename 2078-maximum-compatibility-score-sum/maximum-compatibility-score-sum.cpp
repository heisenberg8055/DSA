class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans = 0;
        int m = students.size();
        int n = students[0].size();
        vector<int>pos;
        for(int i = 0; i < m; i++) {
            pos.push_back(i);
        }
        do {
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if (students[pos[i]][j] == mentors[i][j]) {
                        cnt++;
                    }
                }
            }
            ans = max(ans, cnt);
        }while (next_permutation(pos.begin(), pos.end()));
        return ans;
    }
};