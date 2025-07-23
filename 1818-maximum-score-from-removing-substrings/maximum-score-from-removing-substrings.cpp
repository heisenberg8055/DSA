class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0, n = s.size(), comp = max(x, y), comp1 = min(x, y);
        string reff = "ab";
        if(y > x) {
            reff = "ba";
        }
        stack<string>st;
        for(int i = 0; i < n; i++) {
            if(!st.empty() && st.top() + s[i] == reff) {
                st.pop();
                ans += comp;
            }
            else {
                st.push(string(1, s[i]));
            }
        }
        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        reverse(reff.begin(), reff.end());
        cout << s << " " << reff << ans;
        for(int i = 0; i < s.size(); i++) {
            if(!st.empty() && st.top() + s[i] == reff) {
                st.pop();
                ans += comp1;
            }
            else {
                st.push(string(1, s[i]));
            }
        }
        return ans;
    }
};