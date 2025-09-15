class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int ans = 0;
        int n = arrivals.size();
        int i = 0, j = 0;
        unordered_map<int, int>mp;

        while(j < n) {
            if(++mp[arrivals[j]] > m) {
                ans++;
                mp[arrivals[j]]--;
                arrivals[j] = 0;
            }
            if(j - i + 1 == w) {
                mp[arrivals[i++]]--;
            }
            j++;
        }
        return ans;
    }
};