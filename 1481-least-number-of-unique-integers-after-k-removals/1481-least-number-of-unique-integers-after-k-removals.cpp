class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto &[a,b]:mp)
        {
            q.push({b,a});
        }
        while(k)
        {
            auto it = q.top();
            int c = it.first;
            if(k - c >= 0)
            {
                q.pop();
            }
            k = max(0, k - c);
        }
        return q.size();
    }
};