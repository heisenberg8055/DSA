class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        if(n == 1) {
            return 1;
        }
        vector<int>arr(n, 1);
        for(int i = 1; i < n; i++) {
            if(ratings[i - 1] < ratings[i] && arr[i - 1] >= arr[i]) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i + 1] < ratings[i] && arr[i + 1] >= arr[i]) {
                arr[i] = arr[i + 1] + 1;
            }
        }
        return accumulate(arr.begin(), arr.end(), 0);
    }
};