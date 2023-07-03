class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>ans;
        bool arr[n+1];
        memset(arr, true, sizeof(arr));
        arr[0] = false;
        arr[1] = false;
        for(int i = 2; i * i <= n; i++)
        {
            if(arr[i] == true)
            {
                for(int j = i * i; j <= n; j+=i){
                    arr[j] = false;
                }
            }
        }
        for(int i = 2; i<=n; i++)
        {
            if(arr[i] == true && arr[n - i] == true)
            {
                arr[i] = false;
                arr[n - i] = false;
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};