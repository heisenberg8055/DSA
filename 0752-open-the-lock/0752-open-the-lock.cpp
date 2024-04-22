class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans = 0;
        unordered_map<char, char>nxt = {
            {'0', '1'},
            {'1', '2'},
            {'2', '3'},
            {'3', '4'},
            {'4', '5'},
            {'5', '6'},
            {'6', '7'},
            {'7', '8'},
            {'8', '9'},
            {'9', '0'}
        };
        unordered_map<char, char>prev = {
            {'0', '9'},
            {'1', '0'},
            {'2', '1'},
            {'3', '2'},
            {'4', '3'},
            {'5', '4'},
            {'6', '5'},
            {'7', '6'},
            {'8', '7'},
            {'9', '8'}
        };
        unordered_set<string>vis(deadends.begin(), deadends.end());
        if(vis.find("0000") != vis.end())
        {
            return -1;
        }
        queue<string>q;
        q.push("0000");
        vis.insert("0000");
        while(q.empty() == false)
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                auto it = q.front();
                q.pop();
                if(target == it)
                {
                    return ans;
                }
                for(int i = 0; i < 4; i++)
                {
                    string reff = it;
                    reff[i] = nxt[reff[i]];
                    if(vis.find(reff) == vis.end())
                    {
                        q.push(reff);
                        vis.insert(reff);
                    }
                    reff = it;
                    reff[i] = prev[reff[i]];
                    if(vis.find(reff) == vis.end())
                    {
                        q.push(reff);
                        vis.insert(reff);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};