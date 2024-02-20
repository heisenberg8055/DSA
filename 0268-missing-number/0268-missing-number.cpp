class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int o=0;int i=0;
        for(i=0;i<nums.size();i++)
        {
            o^=i^nums[i];
        }
        return o^i;
    }
};