class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int temp=1;
        vector<vector<int>>ans(n,vector<int>(n,-1));
        int row=n;
        int col=n;
        int i=0;int j=0;
        int it;
        while(i<row&&j<col)
        {
            for(it=j;it<col;it++)
            {
                ans[i][it]=temp;
                temp+=1;
            }
            i++;
            for(it=i;it<row;it++)
            {
                ans[it][col-1]=temp;
                temp+=1;
            }
            col--;
            if(i<row)
            {
                for(it=col-1;it>=j;it--)
                {
                    ans[row-1][it]=temp;
                    temp+=1;
                }
                row--;
            }
            if(j<col)
            {
                for(it=row-1;it>=i;it--)
                {
                    ans[it][j]=temp;
                    temp+=1;
                }
                j++;
            }
        }
        return ans;
    }
};