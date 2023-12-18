class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        vector<int>temp;
        for(int i = 0; i < n; i++)
        {
            if(temp.size() != 3)
            {
                temp.push_back(nums[i]);
            }
            else{
                if(temp[2] - temp[0] <= k)
                {
                    ans.push_back(temp);
                }
                else{
                    return {};
                }
                temp.clear();
                temp.push_back(nums[i]);
            }
        }
        if(temp[2] - temp[0] <= k)
        {
            ans.push_back(temp);
        }
        else
        {
            return {};
        }
        return ans;
    }
};