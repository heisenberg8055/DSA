class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater());
        int i = -1;
        return nums[i+k];
    }
};