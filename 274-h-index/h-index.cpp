class Solution {
public:
    int hIndex(vector<int>& citations) {
        int papers = citations.size();
        vector<int>citationBuckets(papers + 1, 0);
        for(auto it: citations) {
            citationBuckets[min(papers, it)]++;
        }
        int cumPapers = 0;
        for(int hIndex = papers; hIndex >= 0; hIndex--) {
            cumPapers += citationBuckets[hIndex];
            if(cumPapers >= hIndex) {
                return hIndex;
            }
        }
        return 0;
    }
};