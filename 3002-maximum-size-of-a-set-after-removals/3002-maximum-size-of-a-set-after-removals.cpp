class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_set<int>s1(nums1.begin(), nums1.end());
        unordered_set<int>s2(nums2.begin(), nums2.end());
        unordered_set<int>c;
        for(auto it: s1)
        {
            if(s2.find(it) != s2.end())
            {
                c.insert(it);
            }
        }
        int n1 =s1.size(),n2 = s2.size(), c1 = c.size();
        return min(n, min(n1-c1, n/2) + min(n2 - c1, n/2) + c1);
    }
};