class Solution {
private:
    int find_set(int v, vector<int> &parent)
    {
        if(parent[v] == v)
        {
            return v;
        }
        return parent[v] = find_set(parent[v],parent);
    }
    void union_set(int a, int b, vector<int> &parent)
    {
        a = find_set(a,parent);
        b = find_set(b,parent);
        if(a != b)
        {
            parent[b] = a;
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>parent(n);
        for(int i = 0; i < n ;i++)
        {
            parent[i] = i;
        }
        for(auto it:edges)
        {
            union_set(it[0],it[1],parent);
        }
        int t1 = find_set(source,parent);
        int t2 = find_set(destination,parent);
        return t1 == t2;
    }
};