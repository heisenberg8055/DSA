class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        int ne = 1, nn = 0, ans = 0;
        for(int i = 2; i <= n; i++) {
            ans = ne + nn;
            nn = ne;
            ne = ans;
        }
        return ans;
    }
};