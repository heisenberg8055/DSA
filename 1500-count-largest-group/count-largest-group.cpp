class Solution {
public:
    int countLargestGroup(int n) {
        int ans = 0;
        unordered_map<int, int>mp;
        int comp = 0;
        for(int i = 1; i <= n; i++) {
            int temp = i;
            int sum = 0;
            while(temp) {
                sum += temp % 10;
                temp /= 10;
            }
            comp = max(comp, ++mp[sum]);
        }
        for(auto &[a, b]: mp) {
            printf("%d %d\n", a, b);
            if (b == comp) {
                ans++;
            }
        }
        return ans;
    }
};