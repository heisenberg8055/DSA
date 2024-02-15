class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long int>pre(n,0);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            pre[i]+= nums[i] + pre[i-1];
        }
        for(int i = n-1; i > 1; i--){
            if(nums[i] < pre[i-1])
            {
                return pre[i];
            }
        }
        return -1;
    }
};