class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>>q;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                q.push({(double)arr[i] / (double)arr[j], {arr[i], arr[j]}});
            }
        }
        while(k--)
        {
            if(k == 0)
            {
                return {q.top().second.first, q.top().second.second};
            }
            q.pop();
        }
        return {};
    }
};