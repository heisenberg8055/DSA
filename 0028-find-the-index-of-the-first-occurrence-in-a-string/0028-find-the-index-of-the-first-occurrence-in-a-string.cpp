class Solution {
public:
    int strStr(string h, string n) {
        int n1=h.size();
        int nn=n.size();
        if(nn==0)
        {
            return 0;
        }
        for(int i=0;i<n1;i++)
        {
            if(h[i]==n[0])
            {
                if(n1-i<nn)
                {
                    return -1;
                }
                else
                {
                    int j=0;
                    int cnt=0;
                    for(int k=i;k<n1;k++,j++)
                    {
                        if(h[k]==n[j])
                        {
                            cnt++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(cnt==nn)
                    {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};