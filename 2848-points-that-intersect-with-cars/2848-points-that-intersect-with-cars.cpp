class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans = 0;
        vector<int>arr(101, 0);
        for(auto it: nums)
        {
            int f = it[0];
            int l = it[1];
            for(int i = f; i <= l; i++)
            {
                arr[i]++;
            }
        }
        for(int i = 0; i < 101; i++)
        {
            if(arr[i] != 0)
            {
                ans++;
            }
        }
        return ans;
    }
};