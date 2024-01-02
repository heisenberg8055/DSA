class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<vector<int>>ans;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        while(1)
        {
            int c = 0;
            vector<int>temp;
            for(auto it: mp)
            {
                if(it.second != 0)
                {
                    temp.push_back(it.first);
                    mp[it.first]--;
                }
                else{
                    c++;
                }
            }
            if(c == mp.size())
            {
                break;
            }
            ans.push_back(temp);
            c = 0;
            
        }
        return ans;
    }
};