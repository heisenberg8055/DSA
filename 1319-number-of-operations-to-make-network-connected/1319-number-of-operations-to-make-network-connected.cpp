class Solution {
private:
    void dfs(int v, vector<int>& vis, vector<vector<int>>& adj)
    {
        vis[v] = 1;
        for(auto it:adj[v])
        {
            if(vis[it] == 0)
            {
                dfs(it,vis,adj);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans = 0;
        int c = connections.size();
        if(c<n-1)
        {
            return -1;
        }
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i = 0;i<c;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i = 0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans-1;
    }
};