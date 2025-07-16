class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(), c = nums[0]%2, o = 0, e = 0, b = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) {
                e++;
            } else {
                o++;
            }
            if(nums[i] % 2 == c) {
                b++;
                c ^= 1;
            }
        }
        return max(b, max(e, o));
    }
};