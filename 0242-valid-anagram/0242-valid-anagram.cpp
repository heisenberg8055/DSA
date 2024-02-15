class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26];
        int n1 = s.size();
        int n2 = t.size();
        memset(arr,0,sizeof(arr));
        for(int i = 0; i < n1; i++)
        {
            arr[s[i] - 97]++;
        }
        for(int i = 0; i < n2; i++)
        {
            arr[t[i] - 97]--;
        }
        for(int i = 0; i < 26; i++)
        {
            cout<<arr[i]<<" ";
        }
        return count(arr,arr+26,0) == 26;
    }
};