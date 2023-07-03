class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n1 = s.size();
        int n2 = goal.size();
        int i1 = -1, i2 = -1;
        if(n1 != n2 || n1 == 1 || n2 == 1)
        {
            return false;
        }
        if(s == goal)
        {
            vector<int>arr(26,0);
            for(auto &it: goal){
                cout<<it;
                arr[it - 97]++;
                if(arr[it - 97] == 2){
                    return true;
                }
            }
            return false;
        }
        for(int i = 0; i < n1 ;i++)
        {
            if(s[i] != goal[i])
            {
                if(i1 == -1)
                {
                    i1 = i;
                }
                else if(i2 == -1){
                    i2 = i;
                }
                else{
                    return false;
                }
            }
        }
        if(i1 == -1 | i2 == -1){
            return false;
        }
        return s[i1] == goal[i2] && s[i2] == goal[i1];
    }
};