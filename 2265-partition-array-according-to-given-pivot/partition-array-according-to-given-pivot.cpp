class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n);
        int lessI = 0, greatI = n - 1;
        for(int i = 0, j = n - 1; i < n; i++, j--) {
            if(nums[i] < pivot) {
                ans[lessI++] = nums[i];
            }
            if (nums[j] > pivot) {
                ans[greatI--] = nums[j];
            }
        }
        while(lessI <= greatI) {
            ans[lessI++] = pivot;
        }
        return ans;
    }
};