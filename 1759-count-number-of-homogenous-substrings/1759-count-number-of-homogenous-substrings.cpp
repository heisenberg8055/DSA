class Solution {
    long long int mod = 1000000007;
public:
    int countHomogenous(string s) {
        int ans = 0;
        int n = s.size();
        char curr = s[0];
        long long int count = 1;
        for(int i = 1; i < n; i++)
        {
            if(curr == s[i])
            {
                count++;
            }
            else{
                long long int temp = ((count)*(count + 1))/2;
                ans += temp%mod;
                curr = s[i];
                count = 1;
            }
        }
        long long int temp = ((count)*(count + 1))/2;
        ans += temp%mod;
        return ans;
    }
};