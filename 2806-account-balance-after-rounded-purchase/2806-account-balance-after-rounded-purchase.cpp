class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int bal = 100;
        int spent = floor((purchaseAmount + 5)/10) * 10;
        return bal - spent;
    }
};