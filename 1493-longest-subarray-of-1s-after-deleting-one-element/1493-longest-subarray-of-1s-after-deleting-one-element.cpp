class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int zc = 0, oc = 0;
        int i = 0, j = 0;
        while(j < n)
        {
            if(nums[j] == 1)
            {
                oc++;
                j++;
                ans = max(ans, oc);
            }
            else{
                if(zc == 0)
                {
                    j++;
                    zc++;
                }
                else{
                    while(i<j && nums[i] != 0)
                    {
                        if(nums[i] == 1)
                        {
                            oc--;
                        }
                        i++;
                    }
                    i++;
                    j++;
                }
            }
        }
        if(oc == n)
        {
            return n-1;
        }
        if(zc == n)
        {
            return 0;
        }
        return ans;
    }
};