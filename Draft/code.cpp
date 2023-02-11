#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 3;
int n, m;
int a[MAX_N];
int f[MAX_N][30];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) f[i][0] = a[i];

    for (int i = 1; (1 << i) < n; i++) {
        for (int j = 0; j + (1 << i) < n; j++) {
            f[j][i] = min(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
        }
    }

    for (int i = 0; (1 << i) < n; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            cout << j << " " << i << " " << f[j][i] << endl;
        }
    }

    long long sum = 0;
    cin >> m; 
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;

    }

    cout << sum;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

if (fopen("input.txt", "r"))
    freopen("input.txt", "r", stdin);

    int Test = 1;

    while (Test--) {
        solve();
    }
}