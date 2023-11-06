class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>arr(n, 0);
        for(auto it:edges){
            arr[it[1]]++;
        }
        auto reff = min_element(arr.begin(), arr.end()) - arr.begin();
        for(int i = 0; i < n; i++)
        {
            if(i != reff)
            {
                if(arr[i] == arr[reff])
                {
                    return -1;
                }
            }
        }
        return reff;
    }
};