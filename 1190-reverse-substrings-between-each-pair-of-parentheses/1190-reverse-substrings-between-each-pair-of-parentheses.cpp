class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            st.push(string(1,s[i]));
            if(s[i] == ')')
            {
                string temp = "";
                st.pop();
                while(st.top() != "(")
                {
                    temp += st.top();
                    st.pop();
                }
                reverse(temp.begin(), temp.end());
                st.pop();
                st.push(temp);
            }
        }
        string ans = "";
        while(st.size())
        {
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};