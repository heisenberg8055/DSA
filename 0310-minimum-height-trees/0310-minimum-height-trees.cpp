class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
        {
            return {0};
        }
        vector<int>ans;
        vector<int>ind(n,0);
        vector<vector<int>>adj(n);
        for(int i = 0; i < n - 1; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            ind[edges[i][0]]++;
            ind[edges[i][1]]++;
        }
        queue<int>q;
        for(int i = 0; i < n; i++)
        {
            if(ind[i] == 1)
            {
                q.push(i);
            }
        }
        while(q.empty() == false)
        {
            ans.clear();
            int temp = q.size();
            while(temp--)
            {
                int reff = q.front();
                q.pop();
                ans.push_back(reff);
                for(auto it: adj[reff])
                {
                    ind[it]--;
                    if(ind[it] == 1)
                    {
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};