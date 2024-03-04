class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans=0;
        sort(tokens.begin(),tokens.end());
        int score=0;
        int l = 0;
        int r = tokens.size()-1;
        while(l<=r)
        {
            if(tokens[l]>power)
            {
                if(score)
                {
                    power+=tokens[r--];
                    score--;
                    ans=max(ans,score);
                }
                else{
                    break;
                }
            }
            else{
                power-=tokens[l++];
                score++;
                ans=max(ans,score);
            }
        }
        return ans;
    }
};