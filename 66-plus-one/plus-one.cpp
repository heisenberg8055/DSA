class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), rem = 1;
        for(int i = n - 1; i >= 0; i--) {
            int temp = digits[i];
            digits[i] = (temp + rem) % 10;
            rem = (temp + rem) / 10;
        }
        if(rem) {
            digits.resize(n + 1, 1);
            reverse(digits.begin(), digits.end());
        }
        return digits;
    }
};