class Solution {
private:
    static bool cs(vector<int>&arr, vector<int>&brr)
    {
        return arr[1] < brr[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), cs);
        int k = INT_MIN;
        for(auto it:intervals)
        {
            int x = it[0];
            int y = it[1];
            if(x >= k)
            {
                k = y;
            }
            else{
                ans++;
            }
                    
        }
        return ans;
    }
};