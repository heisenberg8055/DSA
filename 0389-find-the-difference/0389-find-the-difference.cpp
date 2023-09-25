class Solution {
public:
    char findTheDifference(string s, string t) {
        int a=0,b=0;
        for(int i=0;i<s.size();i++)
        {
            a+=s[i];
        }
        for(int j=0;j<t.size();j++)
        {
            b+=t[j];
        }
        char f=abs(a-b);
        return f;
    }
};