class Solution {
public:
    long long coloredCells(int n) {
        long long ans = (2 *  pow(n - 1, 2)) + ((2 * n) - 1);
        return ans;
    }
};