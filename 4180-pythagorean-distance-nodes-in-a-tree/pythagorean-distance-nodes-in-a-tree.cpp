class Solution {
private:
    void bfs(int i, vector<int>& reff, vector<vector<int>>& adj) {
        queue<pair<int, int>>q;
        vector<bool>vis(reff.size(), false);
        q.push({i, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int dist = it.second;
            reff[it.first] = dist;
            vis[it.first] = true;
            for(auto &it: adj[it.first]) {
                if(!vis[it]) q.push({it, dist + 1});
            }
        }
    }
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        int ans = 0;
        vector<int>xd(n);
        vector<int>yd(n);
        vector<int>zd(n);
        vector<vector<int>>adj(n);
        for(int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bfs(x, xd, adj);
        bfs(y, yd, adj);
        bfs(z, zd, adj);
        for(int i = 0; i < n; i++) {
            vector<int>reff{xd[i], yd[i], zd[i]};
            sort(reff.begin(), reff.end());
            ans += pow(reff[0], 2) + pow(reff[1], 2) == pow(reff[2], 2) ? 1 : 0;
        }
        return ans;
    }
};