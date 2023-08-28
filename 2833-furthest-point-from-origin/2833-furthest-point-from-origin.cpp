class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int l = 0,r = 0;
        for(int i = 0; i < n; i++)
        {
            if(moves[i] == 'L')
            {
                l++;
            }
            else if(moves[i] == 'R')
            {
                r++;
            }
        }
        return max(l,r) + (n - (l+r)) - min(l,r);
    }
};