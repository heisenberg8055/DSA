class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        unordered_map<string, int>mp;
        for(int i = 0; i < n; )
        {
            mp[word.substr(i, k)]++;
            i+=k;
        }
        int maxi = 0;
        for(auto &[a, b]: mp)
        {
            maxi = max(maxi, b);
        }
        return n / k - maxi;
    }
};