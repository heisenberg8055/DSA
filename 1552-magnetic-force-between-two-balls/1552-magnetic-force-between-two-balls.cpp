class Solution {
private:
    bool help(int x, vector<int>& pos, int m)
    {
        int prev = pos[0];
        int ans = 1;
        for(int i = 1; i < pos.size() && ans < m;i++)
        {
            if(pos[i] - prev >= x)
            {
                ans++;
                prev = pos[i];
            }
        }
        return ans == m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int ans = 0;
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1;
        int high = ceil(position[n - 1] / (m - 1.0));
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(help(mid, position, m))
            {
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};