class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++) {
                    int val1 = nums[i], val2 = nums[j], val3 = nums[k];
                    ans = max(ans, (long long)(val1 - val2) * val3);
                }
            }
        }
        return ans;
    }
};