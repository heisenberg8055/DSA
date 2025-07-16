class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size(), c = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 0)
            {
                c++;
            }
        }
        ans = max(ans, c);
        c = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2)
            {
                c++;
            }
        }
        ans = max(ans, c);
        c = 0;
        int reff = nums[0] % 2;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == reff)
            {
                c++;
                reff ^= 1;
            }
        }
        ans = max(ans, c);
        return ans;
    }
};