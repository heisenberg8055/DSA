class Solution {
private:
    bool chk(string a, string b)
    {
        int i1 = 0;
        int i2 = a.size();
        int j1 = 0;
        int j2 = b.size();
        while(i1 < i2 && j1 < j2)
        {
            if(a[i1] == b[j1])
            {
                i1++;
                j1++;
            }
            else{
                j1++;
            }
        }
        return i1 == i2;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = s.size();
        int nn = dictionary.size();
        sort(dictionary.begin(), dictionary.end(), [&](string a, string b){
            if(a.size() == b.size())
            {
                return a < b;
            }
            else{
                return a.size() > b.size();
            }
        });
        for(int i = 0; i < nn; i++)
        {
            if(chk(dictionary[i], s))
            {
                return dictionary[i];
            }
        }
        return "";
    }
};