class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        vector<int>maxi(n, 0);
        maxi[n - 1] = prices[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            maxi[i] = max(maxi[i + 1], prices[i]);
        }
        for(int i = 0; i < n; i++) {
            cout << maxi[i] <<" ";
            ans = max(ans, maxi[i] - prices[i]);
        }
        return ans;
    }
};