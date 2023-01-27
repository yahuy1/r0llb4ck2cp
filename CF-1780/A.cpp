#include<bits/stdc++.h>
using namespace std;

int n;

void solve() {
    vector <int> a[2];

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x % 2].push_back(i);
    }

    if (a[1].size() >= 3) {
        cout << "YES" << "\n";
        for (int i = 0; i < 3; i++) {
            cout << a[1][i] << " ";
        }
        cout << "\n";
        return;
    }

    if (a[1].size() >= 1 && a[0].size() >= 2) {
        cout << "YES" << "\n";
        for (int i = 0; i < 2; i++) {
            cout << a[0][i] << " ";
        }
        cout << a[1][0] << "\n";
        return;
    }
    cout << "NO" << "\n";
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