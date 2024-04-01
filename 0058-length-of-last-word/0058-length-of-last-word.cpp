class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=-1;
        
        while(s.front()==' ')
        {
            s.erase(s.begin());
        }
        while(s.back()==' ')
        {
            s.pop_back();
        }
        for(int i=s.size();i>=0;i--)
        {
            if(s[i]==' ')
            {
                break;
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
    
};