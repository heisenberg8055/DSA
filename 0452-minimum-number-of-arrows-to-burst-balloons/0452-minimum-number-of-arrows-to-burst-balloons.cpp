class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end(), [&](vector<int> a, vector<int> b){
            if(a[1] == b[1])
            {
                return a[0] <  b[0];
            }
            return a[1] < b[1];
        });
        int n = points.size();
        int i = 0;
        while(i < n)
        {
            int j = i + 1;
            while(j < n && points[i][1] >= points[j][0])
            {
                j++;
            }
            ans++;
            i = j;
        }
        return ans;
    }
};