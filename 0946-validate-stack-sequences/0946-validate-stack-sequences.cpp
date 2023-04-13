class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int i = 0;
        int j = 0;
        int n = pushed.size();
        while(i<n || j<n)
        {
            if(s.empty() == true)
            {
                s.push(pushed[i++]);
            }
            else if(s.top() == popped[j])
            {
                s.pop();
                j++;
            }
            else if(i == n && s.top() != popped[j])
            {
                return false;
            }
            else{
                s.push(pushed[i++]);
            }
        }
        return true;
    }
};