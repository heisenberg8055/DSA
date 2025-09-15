class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double avg = accumulate(nums.begin(), nums.end(), 0);
        avg /= nums.size();
        if (avg < 0) {
            avg = 0;
        }
        unordered_set<int>s(nums.begin(), nums.end());
        for(int i = avg + 1; i <= 101; i++) {
            if (s.find(i) == s.end()) {
                return i;
            }
        }
        return 0;
    }
};