class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
        {
            return 1;
        }
        int ans = 0;    
        int f = 1;
        int s = 1;
        for(int i = 2;i<=n;i++)
        {
            ans = f+s;
            f = s;
            s = ans;
        }
        return ans;
    }
};