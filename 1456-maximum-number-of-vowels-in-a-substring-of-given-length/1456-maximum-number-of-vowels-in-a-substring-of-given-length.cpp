class Solution {
private:
    bool isVowel(char a)
    {
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int ans = 0,temp = 0;
        int i = 0;
        int n = s.size();
        for(;i<k;i++){
            if(isVowel(s[i]))
            {
                temp++;
            }
        }
        ans = max(temp,ans);
        while(i<n)
        {
            if(isVowel(s[i]))
            {
                temp++;
            }
            if(isVowel(s[i-k]))
            {
                temp--;
            }
            ans = max(ans,temp);
            i++;
        }
        return ans;
    }
};