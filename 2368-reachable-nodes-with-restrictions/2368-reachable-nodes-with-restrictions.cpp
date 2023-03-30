class Solution {
private:
    void dfs(int v,unordered_set<int>& s,vector<int> &vis,vector<vector<int>> &adj)
    {
        vis[v] = 1;
        for(auto it:adj[v])
        {
            if(s.find(it) == s.end() && vis[it] == 0)
            {
                dfs(it,s,vis,adj);
            }
        }
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int>s(restricted.begin(),restricted.end());
        vector<vector<int>>adj(n);
        int m = edges.size();
        for(int i = 0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        dfs(0,s,vis,adj);
        return count(vis.begin(),vis.end(),1);
    }
};