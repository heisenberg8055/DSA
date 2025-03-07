class Solution {
private:
    void sieveOfEratosthenes(vector<bool>& p) {
        int n = p.size();
        for (int i = 2; i < sqrt(n); i++) {
            if (p[i]) {
                for (int j = i * i; j < n; j += i) {
                    p[j] = false;
                }
            }
        }
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1, -1};
        vector<bool> primes(right + 1, true);
        primes[1] = false;
        sieveOfEratosthenes(primes);
        vector<int> reff;
        for (int i = left; i <= right; i++) {
            if (primes[i]) {
                reff.push_back(i);
            }
        }
        int mini = INT_MAX;
        if (reff.size()) {
            for (long long i = 0; i < reff.size() - 1; i++) {
                if (i + 1 < reff.size() && mini > reff[i + 1] - reff[i]) {
                    mini = reff[i + 1] - reff[i];
                    ans = {reff[i], reff[i + 1]};
                }
            }
        }
        return ans;
    }
};