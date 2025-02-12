class Solution {
private:
    int getNumberSum(int n){
        int ans = 0;
        while(n) {
            int temp = n % 10;
            ans += temp;
            n /= 10;
        }
        return ans;
    }
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, priority_queue<int>>mp;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int sum = getNumberSum(nums[i]);
            if (mp.find(sum) != mp.end()) {
                ans = max(ans, mp[sum].top() + nums[i]);
            }
            mp[sum].push(nums[i]);
        }
        return ans;
    }
};