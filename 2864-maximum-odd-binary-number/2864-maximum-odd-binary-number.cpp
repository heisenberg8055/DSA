class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int z = count(s.begin(), s.end(), '0');
        int o = n - z;
        o--;
        string on(o, '1');
        string ze(z, '0');
        return on + ze + "1";
    }
};