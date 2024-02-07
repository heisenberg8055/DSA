class Solution {
public:
    string frequencySort(string s) {
        int arr[256] = {0};
        for(auto it:s)
        {
            arr[it]++;
        }
        sort(s.begin(),s.end(),[&](char a, char b){
            return arr[a]>arr[b]||arr[a]==arr[b]&&a<b;
        });
        return s;
    }
};