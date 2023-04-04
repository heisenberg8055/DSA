class Solution {
public:
    int partitionString(string s) {
       int ans = 0;
        unordered_set<char>st;
        int n = s.size();
        for(int i = 0;i<n;i++)
        {
            if(st.find(s[i]) != st.end())
            {
                ans++;
                st.clear();
                st.insert(s[i]);
            }
            else{
                st.insert(s[i]);
            }
        }
        return ++ans;
    }
};