class Solution {
private:
    bool chk(int l, int r, vector<int>& nums) {
        vector<int>arr(nums.begin()+l, nums.begin()+(r+1));
        int n = arr.size();
        int mini = *min_element(arr.begin(),arr.end());
        int maxi = *max_element(arr.begin(),arr.end());
        if(maxi - mini == 0)
        {
            return true;
        }
        if((maxi - mini) % (n-1) != 0)
        {
            return false;
        }
        int diff = (maxi - mini) / (n-1);
        if(diff == 0)
        {
            return true;
        }
        int i = 0;
        while(i<n)
        {
            if(arr[i] == mini +(i*diff))
            {
                i++;
                continue;
            }
            else if((arr[i] - mini) % diff != 0)
            {
                return false;
            }
            else
            {
                int j = ((arr[i] - mini) /diff);
                if(arr[i] == arr[j])
                {
                    return false;
                }
                else
                {
                    swap(arr[i], arr[j]);
                }   
            }
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool>ans(m, 0);
        for(int i = 0;i<m;i++)
        {
            int l1 = l[i];
            int r1 = r[i];
            ans[i] = chk(l1, r1, nums);
        }
        return ans;
    }
};