class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
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
};