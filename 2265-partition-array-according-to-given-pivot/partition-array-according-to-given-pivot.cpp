class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        int n = nums.size();
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int>>l;
        priority_queue<int, vector<int>, greater<int>>g;
        for(int i = 0; i < n; i++) {
            if(nums[i] < p) {
                l.push(i);
            } else if (nums[i] == p){
                cnt++;
            } else {
                g.push(i);
            }
        }
        vector<int>ans(n);
        for(int i = 0; i < n; i++) {
            if (l.empty() == false) {
                auto it = l.top();
                l.pop();
                ans[i] = nums[it];
            } else if (cnt) {
                cnt--;
                ans[i] = p;
            } else {
                auto it = g.top();
                g.pop();
                ans[i] = nums[it];
            }
        }
        return ans;
    }
};