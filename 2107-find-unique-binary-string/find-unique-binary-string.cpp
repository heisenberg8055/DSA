class Solution {
private:
    string help(int num, int length) {
        string ans = "";
        while(num) {
            int temp = num % 2;
            ans = temp ? "1" + ans : "0" + ans;
            num /= 2;
        }
        string reff (length - ans.length(), '0');
        return reff + ans;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i <= pow(2, n - 1); i++) {
            string temp = help(i, n);
            if(!st.contains(temp)) {
                return temp;
            }
        }
        return "";
    }
};