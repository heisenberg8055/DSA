class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>>q1;
        priority_queue<int, vector<int>, greater<int>>q2;
        int i = 0, j = n-1;
        while(k--)
        {
            while(q1.size()<candidates && i<=j)
            {
                q1.push(costs[i++]);
            }
            while(q2.size()<candidates && j>=i)
            {
                q2.push(costs[j--]);
            }
            int a = q1.size() ? q1.top() : INT_MAX;
            int b = q2.size() ? q2.top() : INT_MAX;
            if(a <= b)
            {
                ans += a;
                q1.pop();
            }
            else{
                ans += b;
                q2.pop();
            }
        }
        return ans;
    }
};