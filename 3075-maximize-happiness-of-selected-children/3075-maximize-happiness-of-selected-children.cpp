class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>q;
        for(auto &it: happiness)
        {
            q.push(it);
        }
        long long ans = 0;
        int cnt = 0;
        while(k-- && q.empty() == false)
        {
            long long temp = q.top();
            q.pop();
            if(temp - cnt > 0){
                ans += temp - cnt;
                cnt++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};