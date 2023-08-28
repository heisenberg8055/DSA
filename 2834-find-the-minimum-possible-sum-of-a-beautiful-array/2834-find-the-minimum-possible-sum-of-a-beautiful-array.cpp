class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans = 0;
        unordered_set<int>s;
        int i = 1;
        while(n)
        {
            if(s.find(target - i) == s.end())
            {
                ans += i;
                s.insert(i);
                n--;
            }
            i++;
        }
        return ans;
    }
};
