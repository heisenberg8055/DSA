#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int>pi(n, 0);
    int i = 1, j = 0;
    while(i < n) {
        if (s[i] == s[j]) {
            pi[i] = j + 1;
            i++;
            j++;
        } else if (s[i] != s[j]){
            j != 0 ? j = pi[j - 1] : i++;
        }
    }
    return pi;
}
int main() {
    string pat = "ab";
    vector<int>reff = prefix_function(pat);
    string str = "ababc";
    int n = str.length();
    int i = 0, j = 0;
    vector<int>match;
    while(i < n) {
        if(str[i] == pat[j]) {
            if (j == reff.size() - 1) {
                j = 0;
                match.push_back(i - pat.size() + 1);
                i++;
                continue;
            }
            i++;
            j++;
        } else if(str[i] != pat[j]) {
            j != 0 ? j = reff[j - 1]: i++;
        }
    }
    for(auto it: match) {
        cout << it <<" ";
    }
    return 0;
}