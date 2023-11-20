class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        int n = garbage.size();
        int lp = -1, lm = -1, lg = -1;
        vector<vector<int>>temp(n,vector<int>(3,0));
        for(int i = 0; i < n; i++)
        {
            string curr = garbage[i];
            int reff = curr.size();
            int p = 0, m = 0, g = 0;
            for(int j = 0; j < reff; j++)
            {
                if(curr[j] == 'P')
                {
                    p++;
                    lp = i;
                }
                if(curr[j] == 'M')
                {
                    m++;
                    lm = i;
                }
                if(curr[j] == 'G')
                {
                    g++;
                    lg = i;
                }
            }
            temp[i][0] = p;
            temp[i][1] = m;
            temp[i][2] = g;
        }
        int ap = 0, am = 0, ag = 0;
        ap += temp[0][0];
        am += temp[0][1];
        ag += temp[0][2];
        for(int i = 1; i < n && i <= lp; i++)
        {
            ap+= travel[i-1] + temp[i][0];
        }
        for(int i = 1; i < n && i <= lm; i++)
        {
            am+= travel[i-1] + temp[i][1];
        }
        for(int i = 1; i < n && i <= lg; i++)
        {
            ag+= travel[i-1] + temp[i][2];
        }
        ans += ap+am+ag;
        return ans;
    }
};