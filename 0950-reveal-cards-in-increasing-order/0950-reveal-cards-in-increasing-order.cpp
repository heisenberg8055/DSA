class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end(),greater<int>());
        deque<int>q;
        q.push_back(deck[0]);
        for(int i=1;i<deck.size();i++)
        {
            q.push_front(q.back());
            q.pop_back();
            q.push_front(deck[i]);
        }
        vector<int>ans(q.begin(),q.end());
        return ans;
    }
};