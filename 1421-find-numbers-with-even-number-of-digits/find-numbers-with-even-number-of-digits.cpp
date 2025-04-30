class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto it: nums) {
            int cnt = 0;
            while(it) {
                cnt++;
                it /= 10;
            }
            ans += !(cnt & 1);
        }
        return ans;
    }
};