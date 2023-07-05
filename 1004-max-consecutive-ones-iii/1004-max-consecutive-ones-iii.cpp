class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, zc = 0;
        int j  = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                zc++;
            }
            while(zc > k)
            {
                zc -= nums[j++] == 0;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};