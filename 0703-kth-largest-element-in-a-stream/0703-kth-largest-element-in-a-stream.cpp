class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>>q;
    KthLargest(int K, vector<int>& nums) {
        k=K;
        for(auto it:nums)
        {
            q.push(it);
        }
    }
    int add(int val) {
        q.push(val);
        while(q.size()!=k)
        {
            q.pop();
        }
        int ans=q.top();
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */