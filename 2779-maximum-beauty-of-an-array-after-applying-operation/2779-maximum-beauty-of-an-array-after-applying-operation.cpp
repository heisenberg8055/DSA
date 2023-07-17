class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int offset = 100000;
        int n = nums.size();
        int arr[300002];
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < n; i++)
        {
            int start = nums[i] - k;
            int end = nums[i] + k;
            arr[start + offset]++;
            arr[end + offset + 1]--;
        }
        int ans = arr[0];
        for(int i = 1; i < 300002; i++)
        {
            arr[i] += arr[i-1];
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};