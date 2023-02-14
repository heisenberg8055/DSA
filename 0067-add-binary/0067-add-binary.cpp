class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int c = 0;
        while(i>=0 || j>=0)
        {
            int s = c;
            if(i >= 0)
            {
                s+=a[i--]-'0';
            }
            if(j>=0)
            {
                s+=b[j--]-'0';
            }
            if(s%2 == 1)
            {
                ans+='1';
            }
            if(s%2 ==0)
            {
                ans+='0';
            }
            c = s/2;
        }
        if(c)
        {
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};