typedef long long int lli;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        priority_queue<lli, vector<lli>, greater<lli>>q;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            q.push(nums[i]);
        }
        while(q.size() >= 2 && q.top() < k) {
            lli a = q.top();
            q.pop();
            lli b = q.top();
            q.pop();
            q.push((min(a, b) * 2) + max(a, b));
            ans++;
        }
        return ans;
    }
};