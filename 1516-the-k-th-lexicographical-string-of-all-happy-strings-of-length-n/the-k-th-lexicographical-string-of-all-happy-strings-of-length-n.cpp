class Solution {
private:
    void solve(vector<string> &ans, string &curr, int n, int k, vector<char> &v) {
        if(ans.size() == k) {
            return;
        }
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < 3; i++) {
            if(curr.size() == 0 || curr[curr.size() - 1] != v[i]) {
                curr += v[i];
                solve(ans, curr, n, k, v);
                curr.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> ans;
        vector<char> v = {'a', 'b', 'c'};
        solve(ans,curr, n, k, v);
        if(ans.size() == k) {
            return ans.back();
        }
        else {
            return "";
        }
    }
};