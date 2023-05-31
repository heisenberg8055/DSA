class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = 1;
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        int op = 0;
        sort(nums.begin(),nums.end());
        int i = n-1;
        while(i>=0 && nums[i]>0)
        {
            ans*=nums[i];
            op++;
            i--;
        }
        while(i>=0 && nums[i] == 0)
        {
            i--;
        }
        if(i%2 == 0)
        {
            i--;
        }
        for(int j = 0;j<=i;j++)
        {
            ans*= nums[j];
            op++;
        }
        if(op == 0)
        {
            return 0;
        }
        return ans;
    }
};