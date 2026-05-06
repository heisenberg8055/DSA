class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        queue<int>q;
        for(int i = 0; i < m; i++) {
            for(int j = n - 1; j >= 0; j--) {
                switch (boxGrid[i][j]) {
                    case '#':
                        if(!q.empty()) {
                            int temp = q.front();
                            q.pop();
                            boxGrid[i][temp] = '#';
                            boxGrid[i][j] = '.';
                            q.push(j);
                        }
                        break;
                    case '.':
                        q.push(j);
                        break;
                    case '*':
                        q = {};
                        break;
                }
            }
            cout << "\n";
            q = {};
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = boxGrid[m - 1 - j][i];
            }
        }
        return ans;
    }
};