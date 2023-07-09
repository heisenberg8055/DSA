class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int arr[n];
        memset(arr, -1, sizeof(arr));
        arr[0] = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(abs(nums[j] - nums[i]) <= target && arr[j] != -1)
                {
                    arr[i] = max(arr[i],arr[j]+1);
                }
            }
        }
        return arr[n-1];
    }
};