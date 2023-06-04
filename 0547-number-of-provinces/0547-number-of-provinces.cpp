class Solution {
private:
    void dfs(vector<vector<int>> &adj, int &v, vector<bool> &vis)
    {
        vis[v]=true;
       for(int i=0;i<adj[v].size();i++)
        {
            if(vis[i]==false&&adj[v][i]==1)
            {
                dfs(adj,i,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& is) {
        int ans=0;
        vector<bool>vis(is.size(),false);
        for(int i=0;i<vis.size();i++)
            {
                cout<<vis[i]<<" ";
            }
            cout<<endl;
        for(int i=0;i<is.size();i++)
        {
            if(vis[i]==false)
            {
                dfs(is,i,vis);
                ans++;
            }
            for(int i=0;i<vis.size();i++)
            {
                cout<<vis[i]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};