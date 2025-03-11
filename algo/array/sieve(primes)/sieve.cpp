#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(vector<bool>& p, int n) {
    for(int i = 2; i < sqrt(n + 1); i++) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += i) {
                p[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<bool>p(n + 1, true);
    p[1] = false;
    sieveOfEratosthenes(p, n);
    for(int i = 1; i <= n; i++) {
        if (p[i]) cout << i <<"\n";
    }
    return 0;   
}