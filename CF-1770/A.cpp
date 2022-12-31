#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int MOD = 1e9+ 7;
int n, m;
int a[10003];
 
void solve() {
    cin >> n >> m;
    int ans = 0;
    priority_queue <int, vector <int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
 
    for (int i = 1; i <= m; i++) {
        q.pop();
        int x;
        cin >> x;
        q.push(x);
    }
 
    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }
    cout << ans << "\n";
 
}
 
main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	if (fopen ("input.txt", "r"))
		freopen ("input.txt", "r", stdin);
 
    int test;
    cin >> test;
    
    while (test--) {
       solve(); 
    }  
}