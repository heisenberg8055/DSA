class Solution {
struct comp{
    bool operator() (const string& a, const string& b) const{
        if(a.size() == b.size())
        {
            return a < b;
        }
        return a.size() < b.size();
    }
};
private:
    set<string,comp> substrr(string s)
    {
        set<string, comp>ans;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            string sb = "";
            for(int j = i; j < n; j++)
            {
                sb += s[j];
                ans.insert(sb);
            }
        }
        return ans;
    }
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string>ans(n,"");
        vector<set<string, comp>>reff(n);
        for(int i = 0; i < n; i++)
        {
            reff[i] = substrr(arr[i]);
        }
        for(int i = 0; i < n; i++)
        {
            for(auto it: reff[i])
            {
                int f = 1;
                string temp = it;
                for(int j = 0; j < n; j++)
                {
                    if(j == i)
                    {
                        continue;
                    }
                    if(reff[j].find(temp) != reff[j].end())
                    {
                        f = 0;
                        break;
                    }
                }
                if(f == 1)
                {
                    ans[i] = temp;
                    break;
                }
            }
        }
        return ans;
    }
};