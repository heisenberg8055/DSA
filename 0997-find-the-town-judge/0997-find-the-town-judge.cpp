class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)
        {
            return 1;
        }
        int s=trust.size();
        vector<int>arr(n+1,0);
        for(int i=0;i<s;i++)
        {
            arr[trust[i][1]]++;
            arr[trust[i][0]]--;
        }
        for(int i=0;i<=n;i++)
        {
            if(arr[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};