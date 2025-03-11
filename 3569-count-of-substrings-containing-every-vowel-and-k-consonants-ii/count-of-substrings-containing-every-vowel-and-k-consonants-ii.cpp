class Solution
{
private:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    long long countOfSubstrings(string word, int k)
    {
        long long ans = 0;
        int n = word.size();
        unordered_map<char, int> mp;
        int cc = 0;
        vector<int> nextConsonant(n);
        int lastConsonant = n;
        for (int i = n - 1; i >= 0; i--)
        {
            nextConsonant[i] = lastConsonant;
            if (!isVowel(word[i]))
                lastConsonant = i;
        }
        int left = 0, right = 0;
        while (right < n)
        {
            if (isVowel(word[right]))
            {
                mp[word[right]]++;
            }
            else
            {
                cc++;
            }
            while (left <= right && cc > k)
            {
                if (isVowel(word[left]))
                {
                    if (--mp[word[left]] == 0)
                    {
                        mp.erase(word[left]);
                    }
                }
                else
                {
                    cc--;
                }
                left++;
            }
            while (left < right && mp.size() == 5 && cc == k)
            {
                ans += (nextConsonant[right] - right);
                if (isVowel(word[left]))
                {
                    if (--mp[word[left]] == 0)
                    {
                        mp.erase(word[left]);
                    }
                }
                else
                {
                    cc--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};
