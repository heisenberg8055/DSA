class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans = 0;
        int arr[26];
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            arr[s[i] - 97] = i;
        }
        for(int i = 0; i < n; i++)
        {
            ans += abs(i - arr[t[i] - 97]);
        }
        return ans;
    }
};