class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int temp = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if((num[i] - 48)%2)
            {
                return num.substr(0, n - temp);
            }
            temp++;
        }
        return "";
    }
};