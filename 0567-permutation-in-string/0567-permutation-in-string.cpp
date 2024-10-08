class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        
        vector<int> freq(26,0);
        int rem = 0;
        for (int k = 0; k < s1.size(); k++) {
            if (!freq[s1[k] - 'a'])
                rem++;
            freq[s1[k] - 'a']++;
        }
        
        for (int k = 0; k < s1.size(); k++) {
            if (freq[s2[k] - 'a'] == 1)
                rem--;
            freq[s2[k] - 'a']--;
        }
        if (!rem) {
            return 1;
        }
        for (int k = s1.size(); k < s2.size(); k++) {
            if (!freq[s2[k - s1.size()] - 'a'])
                rem++;
            freq[s2[k - s1.size()] - 'a']++;
            freq[s2[k] - 'a']--;
            if (!freq[s2[k] - 'a'])
                rem--;
            
            if (!rem) {
                return 1;
            }
        }
        
        return 0;
    }
};