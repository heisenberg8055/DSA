class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>>arr;
        int n = names.size();
        for(int i = 0; i < n; i++)
        {
            arr.push_back({names[i], heights[i]});
        }
        sort(arr.begin(), arr.end(), [&](pair<string, int>a, pair<string, int>b){
           return a.second > b.second; 
        });
        vector<string>ans;
        for(auto it: arr)
        {
            ans.push_back(it.first);
        }
        return ans;
    }
};