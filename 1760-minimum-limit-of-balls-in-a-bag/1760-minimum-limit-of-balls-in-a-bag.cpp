class Solution {
private:
    bool isPossible(int maxBallsInBag, vector<int>& nums, int maxOperations){
        int totalOperations = 0;
        for(int num: nums){
            int operations = ceil(num/(double)maxBallsInBag) - 1;
            totalOperations += operations;
            if (totalOperations > maxOperations) {
                return false;
            }
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int r = *max_element(nums.begin(), nums.end());
        int l = 1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(isPossible(mid, nums, maxOperations))
            {
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};