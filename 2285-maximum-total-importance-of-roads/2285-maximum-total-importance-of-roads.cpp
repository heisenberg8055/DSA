class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<vector<int>>adj(n);
        int m = roads.size();
        for(int i = 0;i<m;i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<pair<int,int>>src;
        for(int i = 0;i<n;i++)
        {
            src.push_back({i,adj[i].size()});
        }
        sort(src.begin(),src.end(),[&](pair<int,int>a,pair<int,int>b){
           return a.second<b.second; 
        });
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++)
        {
            mp.insert({src[i].first,i+1});
        }
        for(int i = 0;i<m;i++)
        {
            ans+=mp[roads[i][0]]+mp[roads[i][1]];
        }
        return ans;
    }
};