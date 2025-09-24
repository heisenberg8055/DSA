class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if (n == 0) {
            return "0";
        }
        string ans;
        if ((n > 0) ^ (d > 0)) {
            ans += '-';
        }
        long nn = labs(n), dd = labs(d), r = nn % dd;
        ans += to_string(nn / dd);
        if (r == 0){
            return ans;
        }
        ans += ".";
        unordered_map<long, int>mp;
        while(r) {
            if (mp.find(r) != mp.end()) {
                ans.insert(mp[r], "(");
                ans += ")";
                break;
            }
            mp[r] = ans.size();
            r *= 10;
            ans += to_string(r / dd);
            r %= dd;
        }
        return ans;
    }
};