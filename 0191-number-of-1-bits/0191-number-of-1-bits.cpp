class Solution {
public:
    int ans=0;
    int hammingWeight(uint32_t n) {
        if(n==0)
        {
            return ans;
        }
        ans+=n&1;
        return hammingWeight(n/2);
    }
};