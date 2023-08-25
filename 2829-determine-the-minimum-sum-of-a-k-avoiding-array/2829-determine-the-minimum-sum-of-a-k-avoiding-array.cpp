class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0, count = 0;
        unordered_set<int>s;
        for(int i = 1; i <= 100 && count < n; i++)
        {
            if(s.find(i) == s.end())
            {
                count++;
                ans += i;
                s.insert(k - i);    
            }
        }
        return ans;
    }
};