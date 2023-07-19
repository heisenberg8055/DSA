class Solution {
public:
    bool haveConflict(vector<string>& a, vector<string>& b) {
        return a[0] < b[0] ? a[1] >= b[0] : a[0] <= b[1];
    }
};