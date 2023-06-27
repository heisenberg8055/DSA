class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>>ans;
        set<pair<int,int>>s;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        q.push({nums1[0]+nums2[0],{0,0}});
        s.insert({0,0});
        while(q.size() && k--)
        {
            auto it = q.top();
            q.pop();
            int i = it.second.first;
            int j = it.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(i + 1 < n1 && s.find({i+1,j}) == s.end())
            {
                q.push({nums1[i+1]+ nums2[j],{i+1,j}});
                s.insert({i+1,j});
            }
            if(j+1 < n2 && s.find({i, j+1}) == s.end())
            {
                q.push({nums1[i]+nums2[j+1], {i,j+1}});
                s.insert({i,j+1});
            }
        }
        return ans;
    }
};