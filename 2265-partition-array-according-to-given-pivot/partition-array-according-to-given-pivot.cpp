class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        int n = nums.size();
        int cnt = 0;
        deque<int>l;
        deque<int>g;
        for(int i = 0; i < n; i++) {
            if(nums[i] < p) {
                l.push_back(i);
            } else if (nums[i] == p){
                cnt++;
            } else {
                g.push_back(i);
            }
        }
        vector<int>ans(n);
        for(int i = 0; i < n; i++) {
            if (l.empty() == false) {
                auto it = l.front();
                l.pop_front();
                ans[i] = nums[it];
            } else if (cnt) {
                cnt--;
                ans[i] = p;
            } else {
                auto it = g.front();
                g.pop_front();
                ans[i] = nums[it];
            }
        }
        return ans;
    }
};