class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for(auto it:nums)
        {
            it%2 == 0 ? c++: c=c;
        }
        return c>=2;
    }
};