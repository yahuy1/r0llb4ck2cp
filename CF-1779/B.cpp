#include<bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    if (n % 2 == 0) {
        cout << "YES" << "\n";
        for (int i = 1; i <= n; i += 2) {
            cout << 1 << " " << -1 << " ";
        }
        cout << "\n";
    } else {
        if (n == 3) cout << "NO" << "\n";
        else {
            cout << "YES" << "\n";
            for (int i = 1; i <= n / 2; i++) {
                cout << n / 2 - 1 << " " << - (n / 2) << " ";
            } 
            cout << n / 2 - 1 << "\n";
        }
    }
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