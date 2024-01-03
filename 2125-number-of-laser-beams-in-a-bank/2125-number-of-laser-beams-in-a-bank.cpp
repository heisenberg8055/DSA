class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int n = bank.size();
        vector<int>arr(n,0);
        for(int i = 0; i < n; i++)
        {
            arr[i]+=count(bank[i].begin(),bank[i].end(),'1');
        }
        int prev = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(arr[i])
            {
                ans += prev *arr[i];
                prev = arr[i];
            }
        }
        return ans;
    }
};