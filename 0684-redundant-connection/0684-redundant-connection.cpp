class Solution {
private:
    int find(int x, vector<int> &parent)
    {
        if(parent[x] != x)
        {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    void unionx(int x, int y, vector<int> &parent)
    {
        parent[x] = y;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        int n = edges.size();
        vector<int>parent(n+1,0);
        for(int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }
        for(int i = 0; i < n; i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            int px = find(x,parent);
            int py = find(y,parent);
            if(px == py)
            {
                ans = edges[i];
            }
            else{
                unionx(px, py, parent);
            }
        }
        return ans;
    }
};