class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>s;
        for(int i = 0; i < n; i++)
        {
            if(s.find(target - nums[i]) != s.end())
            {
                return {i,s[target - nums[i]]};
            }
            s.insert({nums[i],i});
        }
        return {};
    }
};