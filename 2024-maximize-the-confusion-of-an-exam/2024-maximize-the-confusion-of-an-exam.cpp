class Solution {
private:
    int help(string &answerKey, int &n, int &k, char ver)
    {
        int ans = 0;
        int c = 0;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            if(answerKey[i] != ver)
            {
                c++;
                while(c > k)
                {
                    c -= answerKey[start++] != ver;
                }
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int tc = help(answerKey, n, k, 'T');
        int fc = help(answerKey, n, k, 'F');
        return max(tc, fc);
    }
};