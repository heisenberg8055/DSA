class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        vector<pair<int, int>>arr(26, {INT_MAX, -1});
        int n = word.size();
        for(int i = 0; i < n; i++)
        {
            if(islower(word[i]))
            {
                arr[word[i] - 97].first = i;
            }
            else{
                if(arr[word[i] - 65].second == -1)
                {
                    arr[word[i] - 65].second = i;
                }
            }
        }
        for(auto &[a, b]: arr)
        {
            ans += a < b;
        }
        return ans;
    }
};