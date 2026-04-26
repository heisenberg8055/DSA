class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for(int i = n; i >= 1; i--) {
            if(citations[n - i] >= i) {
                return i;
            }
        }
        return 0;
    }
};