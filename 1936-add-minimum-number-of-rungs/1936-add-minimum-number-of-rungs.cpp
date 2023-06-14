class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size();
        int ans = 0;
        int prev = 0;
        for(int i = 0;i<n;i++)
        {
            if(rungs[i] - prev > dist)
            {
                int temp = (rungs[i] - prev -1) / dist;
                ans += temp;
                prev += dist * temp;
                i--;
            }
            else{
                prev = rungs[i];
           }
        }
        return ans;
    }
};