class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        int n = num.size();
        int c = 0;
        n--;
        while(n>=0)
        {
            int nu = 0;
            if(k)
            {
                nu = k%10;
                k/=10;
            }
            int sum = num[n--] + c + nu;
            ans.push_back((sum)%10);
            sum>=10?c=1:c=0;
        }
        while(k)
        {
            int temp = k%10;
            ans.push_back((temp+c)%10);
            temp+c>=10?c=1:c=0;
            k/=10;
        }
        if(c)
        {
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};