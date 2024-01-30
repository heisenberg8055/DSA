class Solution {
private:
    int calc(int a, int b, string temp)
    {
        if(temp == "+")
        {
            return a + b;
        }
        if(temp == "-")
        {
            return a - b;
        }
        if(temp == "*")
        {
            return a * b;
        }
        if(temp == "/")
        {
            return a / b;
        }
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int n = tokens.size();
        for(int i = 0; i < n; i++)
        {
            string temp = tokens[i];
            if(temp == "+" || temp == "-" || temp == "*" || temp == "/")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int ans = calc(a,b,temp);
                s.push(ans);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};