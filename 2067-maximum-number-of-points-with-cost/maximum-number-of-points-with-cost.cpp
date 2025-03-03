class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> prev(n);
        for(int i = 0; i < n; i++) {
            prev[i] = points[0][i];
        }
        for(int i = 0; i < m - 1; i++) {
            vector<long long> l(n);
            vector<long long> r(n);
            vector<long long> c(n);
            l[0] = prev[0];
            for(int j = 1; j < n; j++) {
                l[j] = max(l[j - 1] - 1, prev[j]);
            }
            r[n - 1] = prev[n - 1];
            for(int j = n - 2; j >= 0; j--) {
                r[j] = max(r[j + 1] - 1, prev[j]);
            }
            for(int j = 0; j < n; j++) {
                c[j] = max(l[j], r[j]) + points[i + 1][j];
            }
            prev = c;
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, prev[i]);
        }
        return ans;
    }
};