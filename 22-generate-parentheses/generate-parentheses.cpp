class Solution {
private:
    void help(vector<string>& ans, int l, int r, int n, string curr) {
        if(l + r == 2 * n) {
            ans.push_back(curr);
            return;
        }
        if (l < n) {
            help(ans, l + 1, r, n, curr + "(");
        }
        if (r < l) {
            help(ans, l, r + 1, n, curr + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        help(ans, 0, 0, n, "");
        return ans;
    }
};