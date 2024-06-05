class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
        int arr[26];
        memset(arr, 0, sizeof(arr));
        string temp = words[0];
        for(int i = 0 ; i < temp.size(); i++)
        {
            arr[temp[i] - 97]++;
        }
        for(int i = 1; i < n; i++)
        {
            string temp = words[i];
            int brr[26];
            memset(brr, 0, sizeof(brr));
            for(int j = 0; j < temp.size(); j++)
            {
                brr[temp[j] - 97]++;
            }
            for(int k = 0; k < 26; k++)
            {
                arr[k] = min(arr[k], brr[k]);
            }
        }
        for(int i = 0; i < 26; i++)
        {
            if(arr[i])
            {
                for(int j = 0; j < arr[i]; j++)
                {
                    ans.push_back(string(1, 97 + i));
                }
            }
        }
        return ans;
    }
};