class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            int f=1;
            for(int j=0;j<temp.size()/2;j++)
            {
                if(temp[j]!=temp[temp.size()-j-1])
                {
                   f=0;break; 
                }
            }
            if(f)
            {
                ans=temp;break;
            }
        }
        return ans;
    }
};