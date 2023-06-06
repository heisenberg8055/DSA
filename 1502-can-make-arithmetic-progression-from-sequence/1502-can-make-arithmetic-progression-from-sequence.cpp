class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int>s;
        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());
        if(maxi - mini == 0)
        {
            return true;
        }
        if((maxi - mini) % (n-1) != 0)
        {
            return false;
        }
        int diff = (maxi - mini) / (n - 1);
        for(int i = 0;i<n;i++)
        {
            if((arr[i] - mini) % diff != 0)
            {
                return false;
            }
            else{
                s.insert(arr[i]);
            }
        }
        if(s.size() != n)
        {
            return false;
        }
        return true;
    }
};