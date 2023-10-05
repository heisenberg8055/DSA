class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int n1 = -1,n2=-1;
        int c1=0,c2=0;
        for(auto it:nums)
        {
            if(n1==it)
            {
                c1++;
            }
            else if(n2==it)
            {
                c2++;
            }
            else if(c1==0)
            {
                n1=it,c1=1;
            }
            else if(c2==0){
                n2=it,c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=c2=0;
        for(auto it:nums)
        {
            if(n1==it){
                c1++;
        }
            else if(n2==it){
                c2++;
            }
        }
        if(c1>nums.size()/3)
        {
            ans.push_back(n1);
        }
        if(c2>nums.size()/3)
        {
            ans.push_back(n2);
        }
        return ans;
    }
};