class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s;
        for(auto &it: nums) {
            s.insert(it);
        }
        auto it = s.begin();
        return  *it > k ? s.size() : *it == k ? s.size() - 1 : -1;
    }
};