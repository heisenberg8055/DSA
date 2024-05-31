class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        long int xorr = 0;
        for(int i = 0; i < n; i++)
        {
            xorr ^= nums[i];
        }
        int b1 = 0, b2 = 0;
        xorr = (xorr & xorr - 1) ^ xorr;
        for(int i = 0; i < n; i++)
        {
            if(xorr & nums[i])
            {
                b1 ^= nums[i];
            }
            else{
                b2 ^= nums[i];
            }
        }
        return {b1, b2};
    }
};