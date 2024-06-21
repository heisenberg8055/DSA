class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int n = grumpy.size(), temp = 0;
        for(int i = 0; i < n; i++)
        {
            temp += grumpy[i] == 0 ? customers[i] : 0;
        }
        int i = 0, count = 0;
        while(i < n)
        {
            if(count < minutes)
            {
                temp += grumpy[i] ? customers[i] : 0;
                ans = max(ans, temp);
                i++, count++;
            }
            if(count == minutes)
            {
                temp -= grumpy[i - minutes] == 1 ? customers[i - minutes] : 0;
                count--;
            }
        }
        return ans;
    }
};