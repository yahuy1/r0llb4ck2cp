#include<bits/stdc++.h>
using namespace std;

int n;
string s;

void solve() {
    cin >> n;
    cin >> s; s = " " + s;

    for (int i = 1; i < n; i++) {
        if (s[i] == 'L' && s[i + 1] == 'R') {
            cout << i << "\n";
            return;
        }
        if (s[i] == 'R' && s[i + 1] == 'L') {
            cout << 0 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

if (fopen("input.txt", "r"))
    freopen("input.txt", "r", stdin);

    int Test;
    cin >> Test;

    while (Test--) {
        solve();
    }
}