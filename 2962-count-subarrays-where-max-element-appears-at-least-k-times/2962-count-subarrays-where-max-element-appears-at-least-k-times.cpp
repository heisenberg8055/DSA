class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int max_elemen = *max_element(nums.begin(), nums.end());
        vector<int>temp;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == max_elemen)
            {
                temp.push_back(i);
            }
            int freq = temp.size();
            if(freq >= k)
            {
                ans += temp[freq - k] + 1;
            }
        }
        return ans;
    }
};