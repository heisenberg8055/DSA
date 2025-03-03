class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n);
        int low = 0, same = 0;
        for(int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                low++;
            } else if (nums[i] == pivot) {
                same++;
            }
        }
        int high = low + same;
        same = low;
        low = 0;
        for(int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[low++] = nums[i];
            } else if (nums[i] == pivot) {
                ans[same++] = nums[i];
            } else {
                ans[high++] = nums[i];
            }
        }
        return ans;
    }
};