class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a||b||c)
        {
            int a1 = a%2;
            a/=2;
            int b1 = b%2;
            b/=2;
            int c1 = c%2;
            c/=2;
            if(c1)
            {
                if(a1 == 0 && b1 == 0)
                {
                    ans+=1;
                }
            }
            else{
                ans+=a1+b1;
            }
        }
        return ans;
    }
};