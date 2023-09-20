class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target=-x;
        for(auto it:nums)
        {
            target+=it;
        }
        if(target==0)
        {
            return nums.size();
        }
        if(target<0)
        {
            return -1;
        }
        int res=-1;
        int sum=0;
        int left=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>target)
            {
                sum-=nums[left++];
            }
            if(sum==target)
            {
                res=max(res,i-left+1);
            }
        }
        return res==-1?-1:nums.size()-res;
    }
};