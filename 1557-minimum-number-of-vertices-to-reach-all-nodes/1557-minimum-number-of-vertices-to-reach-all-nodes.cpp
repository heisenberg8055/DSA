class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        set<int>temp;
        for(auto it:edges)
        {
            temp.insert(it[1]);
        }
        for(int i=0;i<n;i++)
        {
            if(temp.find(i)==temp.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};