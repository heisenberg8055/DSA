class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, int>mp;
        for(auto &it: nums) {
            mp[it]++;
        }
        auto it = mp.begin();
        cout << it -> first;
        return it -> first > k ? mp.size() : it -> first == k ? mp.size() - 1 : -1;
    }
};