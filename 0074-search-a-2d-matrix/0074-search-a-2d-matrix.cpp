class Solution {
private:
    bool help(vector<int> &arr, int n, int target)
    {
        int l = 0; int r = n -1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(arr[mid] == target)
            {
                return true;
            }
            if(arr[mid] < target)
            {
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m ; i++){
            if(matrix[i][0] <= target && matrix[i][n-1] >= target)
            {
                return help(matrix[i], n, target);
            }
            else if(matrix[i][0] > target)
            {
                return false;
            }
        }
        return false;
    }
};