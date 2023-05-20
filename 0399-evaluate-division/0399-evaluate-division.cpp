class Solution {
private:
    double dfs(string s, string d, unordered_map<string,unordered_map<string,double>> &mp,unordered_set<string> &vis)
    {
        if(mp[s].find(d)!=mp[s].end())
        {
            return mp[s][d];
        }
        for(auto node:mp[s])
        {
            if(vis.find(node.first)==vis.end())
            {
                vis.insert(node.first);
                double val = dfs(node.first,d, mp, vis);
                if(val)
                {
                    mp[s][d]=node.second*val;
                    return mp[s][d];
                }
            }
        }
        return 0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
        int n=equations.size();
        unordered_map<string,unordered_map<string, double>>mp;
        for(int i=0;i<n;i++)
        {
            mp[equations[i][0]][equations[i][1]]=values[i];
            mp[equations[i][1]][equations[i][0]]=(double)1/(values[i]);
        }
        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string>vis;
            double val = dfs(queries[i][0],queries[i][1],mp,vis);
            if(val==0)
            {
                ans.push_back(-1.0);
            }
            else
            {
                ans.push_back(val);
            }
        }
        return ans;
    }
};