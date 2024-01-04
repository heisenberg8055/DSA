class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        int n = tasks.size();
        unordered_map<int,int>mp;
        for(auto it: tasks)
        {
            mp[it]++;
        }
        for(auto [_,c]: mp){
            if(c == 1)
            {
                return -1;
            }
            ans += c/3 + (c%3 > 0);
        }
        return ans;
    }
};