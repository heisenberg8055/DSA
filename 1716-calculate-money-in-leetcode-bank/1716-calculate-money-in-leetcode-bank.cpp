class Solution {
private:
    int sumn(int n,int i)
    {
        return (((n) * (n+1))/2) - (((i) * (i+1))/2);
    }
public:
    int totalMoney(int n) {
        int ans = 0;
        int rem = n%7;
        int weeks = n/7;
        for(int i = 4 ; i < 4 + weeks; i++)
        {
            ans += 7 * i;
        }
        ans += sumn(rem + weeks, weeks);
        return ans;
    }
};