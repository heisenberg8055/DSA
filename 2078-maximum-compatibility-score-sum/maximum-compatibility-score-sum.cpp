class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans = 0;
        int m = students.size();
        int n = students[0].size();
        sort(students.begin(), students.end());
        do {
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if (students[i][j] == mentors[i][j]) {
                        cnt++;
                    }
                }
            }
            ans = max(ans, cnt);
        }while (next_permutation(students.begin(), students.end()));
        return ans;
    }
};