class Solution {
private:
    int dfs(int i, int s, int w, unordered_map<int,vector<pair<int, int>>> &mp, int ss)
    {
        int cnt = w % ss ? 0 : 1;
        for(auto [a,b]: mp[i])
        {
            if(a != s)
            {
                cnt += dfs(a, i, w+b, mp, ss);
            }
        }
        return cnt;
    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i = 0; i < n - 1; i++)
        {
            mp[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            mp[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int>ans(n);
        for(int i = 0; i < n; i++)
        {
            int res = 0, cnt = 0;
            for(auto &[a,b]: mp[i])
            {
                int temp = dfs(a,i,b,mp,signalSpeed);
                res += cnt * temp;
                cnt += temp;
            }
            ans[i] = res;
        }
        return ans;
    }
};