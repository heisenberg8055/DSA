class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int c=0;
            int temp=i;
            while(temp)
            {
                c+=temp&1;
                temp>>=1;
            }
            ans.push_back(c);
        }
        return ans;
    }
};