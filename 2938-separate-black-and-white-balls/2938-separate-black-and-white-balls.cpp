class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long int ans = 0;
        int count = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                count++;
                continue;
            }
            if(s[i] == '1')
            {
                ans += count;
            }
        }
        return ans;
    }
};