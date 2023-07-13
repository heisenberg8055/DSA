class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i = 0; i < n; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>ind(numCourses,0);
        for(int i = 0; i < numCourses; i++)
        {
            for(auto it: adj[i])
            {
                ind[it]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < numCourses; i++)
        {
            if(ind[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(q.size())
        {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it:adj[temp])
            {
                if(--ind[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ans.size() == numCourses;
    }
};