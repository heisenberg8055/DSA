class Solution {
private:
    int help(vector<int>& b, int mid, int k)
    {
        int ans = 0;
        int count = 0;
        int n = b.size();
        for(int i = 0; i < n; i++)
        {
            if(b[i] <= mid)
            {
                count++;
            }
            else{
                count = 0;
            }
            if(count == k)
            {
                ans++;
                count = 0;
            }
        }
        return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int n = bloomDay.size();
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while(left <= right)
        {
            int mid = (left + ((right - left)/2));
            if(help(bloomDay, mid, k) >= m)
            {
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};