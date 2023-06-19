class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while(mainTank)
        {
            ans++;
            mainTank--;
            if(ans > 0 && ans % 5 == 0 && additionalTank)
            {
                mainTank++;
                additionalTank--;
            }
        }
        return ans * 10;
    }
};