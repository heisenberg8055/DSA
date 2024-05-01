class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans="";
        string temp="";
        int f=1;
        for(int i=0;i<word.size();i++)
        {
            temp+=word[i];
            if(word[i]==ch&&f)
            {
                reverse(temp.begin(),temp.end());
                ans+=temp;
                f=0;
                temp="";
            }
        }
        ans+=temp;
        return ans;
    }
};