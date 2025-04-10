class Solution {
public:
    long long cnt[16] = {};
long long count(char l, const string &n, const string &s) {
    long long res = cnt[n.size() - 1], i = 0, sz = n.size() - s.size();
    do
        res += i == sz ? n.substr(i) >= s : cnt[n.size() - i - 1] * (min(l, n[i]) - '1' + (i > 0));
    while (i < sz && n[i++] < l);
    return res;
} 
long long numberOfPowerfulInt(long long start, long long finish, int limit, const string &s) {
    for (int i = s.size(); i < 16; ++i)
        cnt[i] = i == s.size() ? 1 : cnt[i - 1] * (limit + 1);
    return count('1' + limit, to_string(finish), s) - count('1' + limit, to_string(start - 1), s);
}
};