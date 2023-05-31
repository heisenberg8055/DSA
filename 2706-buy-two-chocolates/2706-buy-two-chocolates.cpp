class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int x = INT_MAX, y = INT_MAX;
        for(auto &it:prices)
        {
            if(x>it)
            {
                y = x;
                x = it;
            }
            else if(y>it)
            {
                y = it;
            }
        }
        return x+y<=money? money - (x+y): money;
    }
};