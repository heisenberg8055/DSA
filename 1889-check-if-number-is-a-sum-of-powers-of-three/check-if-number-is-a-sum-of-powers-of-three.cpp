class Solution {
private:
    bool help(int i, int curr, int n, vector<int>& nums) {
        if(curr == n) {
            return true;
        } else if ( curr > n) {
            return false;
        }
        if (i < 0) {
            return curr == n;
        }
        bool p = help(i - 1, curr + nums[i], n, nums);
        bool nP = help(i - 1, curr, n, nums);
        return nP || p;
    }
public:
    bool checkPowersOfThree(int n) {
        vector<int>nums;
        int reff = 0;
        while(pow(3, reff) <= n) {
            nums.push_back(pow(3, reff));
            reff++;
        }
        return help(nums.size() - 1, 0, n, nums);
    }
};