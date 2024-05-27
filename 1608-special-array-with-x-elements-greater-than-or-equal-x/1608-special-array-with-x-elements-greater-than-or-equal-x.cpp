class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int prev = -1;
        if(nums[nums.size() - 1] == 0)
        {
            return -1;
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= n - i && prev < n - i)
            {
                return n - i;
            }
            prev = nums[i];
        }
        return -1;
    }
};