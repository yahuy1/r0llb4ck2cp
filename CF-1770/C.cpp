#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[103];
int isPrime[103];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] == a[j]) {
                cout << "no" << "\n";
                return;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        } 

        if (!isPrime) continue;

        vector <int> cnt(i, 0);

        for (int j = 1; j <= n; j++) {
            cnt[a[j] % i]++;
        }

        if (*min_element(cnt.begin(), cnt.end()) >= 2) {
            cout << "no" << "\n";
            return;
        }
    }

    cout << "yes" << "\n";
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