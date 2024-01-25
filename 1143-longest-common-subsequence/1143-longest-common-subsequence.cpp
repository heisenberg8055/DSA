class Solution {
public:
   int longestCommonSubsequence(string &a, string &b) {
    int n1 = a.size();
    int n2 = b.size();
    int m[n1+1][n2+1] ;
    memset(m,0,sizeof(m));
    for (auto i = 0; i < n1; ++i)
        for (auto j = 0; j < n2; ++j)
            m[i + 1][j + 1] = a[i] == b[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
    return m[a.size()][b.size()];
}
};