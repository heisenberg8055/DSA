class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
        {
            return 0;
        }
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2 ; i++){
            int k = i + 2;
            for(int j = i + 1; j < n - 1 && nums[i] != 0; j++)
            {
                while(k < n && nums[i] + nums[j] > nums[k])
                {
                    k++;
                    ans += k - j - 1;
                }
            }
        }
        return ans;
    }
};