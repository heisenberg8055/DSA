class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>st;
        unordered_set<int>prev;
        prev.insert(0);
        for(auto it: arr) {
            unordered_set<int>curr;
            for(auto it1: prev) {
                curr.insert(it | it1);
            }
            curr.insert(it);
            prev = curr;
            st.insert(curr.begin(), curr.end());
        }
        return st.size();
    }
};