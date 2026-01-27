class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        int n1 = edges.size();
        int cost = 0;
        vector<vector<pair<int, int>>>adj(n);
        for(int i = 0; i < n1; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2] * 2});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
        q.push({0, 0});
        vector<int>dis(n, INT_MAX);
        dis[0] = 0;
        while(!q.empty()) {
            auto it = q.top();
            q.pop();
            int u = it.second;
            for(auto &it1: adj[u]) {
                int v = it1.first;
                int y = it1.second;
                if(dis[v] > dis[u] + y) {
                    dis[v] = dis[u] + y;
                    q.push({dis[v], v});
                }
            }
        }
        return dis[n - 1] == INT_MAX ? -1 : dis[n - 1];
    }
};