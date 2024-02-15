class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = -1;
        long long prevSum = 0;
        for(auto it: nums)
        {
            if(it < prevSum)
            {
                ans = prevSum + it;
            }
            prevSum+=it;
        }
        return ans;
    }
};