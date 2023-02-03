#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n, m;
int a[200003];
 
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    priority_queue <int> q;
    int sum = 0;
    int ans = 0;
    
    for (int i = m + 1; i <= n; i++) {
        sum += a[i];
        q.push(-a[i]);
        while (sum < 0) {
            sum += 2 * q.top();
            ans ++;
            q.pop();
        }
    }
 
    while (!q.empty()) q.pop();
    sum = 0;
    for (int i = m; i >= 2; i--) {
        a[i] *= -1;
        sum += a[i];
        q.push(-a[i]);
        while (sum < 0) {
            sum += 2 * q.top();
            ans ++;
            q.pop();
        }
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