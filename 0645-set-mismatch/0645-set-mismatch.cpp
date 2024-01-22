class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        unordered_set<int>s;
        for(int i = 0; i < n; i++)
        {
            if(s.find(nums[i]) != s.end())
            {
                ans.push_back(nums[i]);
            }
            s.insert(nums[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(s.find(i) == s.end())
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};