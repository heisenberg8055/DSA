class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>reff;
        for(auto it: logs)
        {
            if(it == "./")
            {
                continue;
            }
            else if(it == "../")
            {
                if(!reff.empty())
                reff.pop();
            }
            else{
                reff.push("1");
            }
        }
        return reff.size();
    }
};