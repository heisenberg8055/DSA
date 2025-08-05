class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> reff(n, -1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(fruits[i] <= baskets[j] && reff[j] == -1) {
                    reff[j] = i;
                    break;
                }
            }
        }
        return count(reff.begin(), reff.end(), -1);
    }
};