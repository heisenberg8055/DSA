class Solution {
private:
    bool help(vector<int>& nums, vector<vector<int>>& q, int k) {
        int n = nums.size(), sum = 0;
        vector<int>diff(n + 1, 0);
        for(int i = 0; i < k; i++) {
            int start = q[i][0], end = q[i][1], val = q[i][2];
            diff[start] += val;
            diff[end + 1] -= val;
        }
        for(int i = 0; i < n; i++) {
            sum += diff[i];
            if (sum < nums[i]) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size();
        int n = queries.size();
        if (!help(nums, queries, n)) {
            return -1;
        }
        int l = 0, r = n;
        while(l <= r) {
            int mid = l + ((r - l) / 2);
            if (help(nums, queries, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};