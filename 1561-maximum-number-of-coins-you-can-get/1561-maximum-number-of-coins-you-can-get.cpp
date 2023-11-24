class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int j = 0;
        for(int i = n - 1; i >= 0 && j < i; i-=2)
        {
            ans += piles[i-1];
            j++;
        }
        return ans;
    }
};