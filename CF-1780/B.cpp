#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[200003];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        ans = max(ans, gcd(a[i], a[n]));
    }

    cout << ans << "\n";
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