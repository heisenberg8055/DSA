class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++)
        {
            int target = 0 - nums[i];
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                if(nums[l] + nums[r] == target)
                {
                    s.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] < target)
                {
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        vector<vector<int>>ans(s.begin(), s.end());
        return ans;
    }
};