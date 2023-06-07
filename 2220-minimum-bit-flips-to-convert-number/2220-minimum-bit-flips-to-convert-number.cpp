class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        while(start!=0 | goal!= 0)
        {
            int s1 = start&1;
            int g1 = goal&1;
            ans+=!(s1 == g1);
            start>>=1;
            goal>>=1;
        }
        return ans;
    }
};