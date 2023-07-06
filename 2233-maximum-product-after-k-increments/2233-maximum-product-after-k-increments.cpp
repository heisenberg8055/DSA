class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long int ans = 1;
        priority_queue<int, vector<int>, greater<int>>q(nums.begin(), nums.end());
        while(k--)
        {
            int temp = q.top();
            q.pop();
            q.push(++temp);
        
        }
        while(q.empty() == false)
        {
            ans = (ans * q.top()) % 1000000007;
            q.pop();
        }
        return ans;
    }
};