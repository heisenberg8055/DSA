class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size(), i = 0;
        while(i<n)
        {
            long long int start = nums[i];
            long long int prev = nums[i];
            while(i < n - 1  && nums[i+1] == 1 + prev)
            {
                prev = nums[++i];
            }
            if(start == prev)
            {
                ans.push_back(to_string(start));
                i++;
            }
            else{
                ans.push_back(to_string(start)+"->"+to_string(prev));
                i++;
            }
        }
        return ans;
    }
};