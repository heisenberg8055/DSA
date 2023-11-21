class Solution {
private:
    int rev(int n)
    {
        int ans = 0;
        while(n){
            int temp = n%10;
            n/=10;
            ans = (ans * 10) + temp;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int>mp;
        long long int mod = 1000000007;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            nums[i] = nums[i] - rev(nums[i]);
            if(mp.find(nums[i]) != mp.end())
            {
                ans = (ans + mp[nums[i]]) % mod;
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};