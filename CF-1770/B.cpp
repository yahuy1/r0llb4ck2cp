#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int MOD = 1e9+ 7;
int n, k;
 
void solve() {
    cin >> n >> k;
    int l = 1;
    int r = n;
 
    while (l <= r) {
        for (int i = 1; i < k ;i++) {
            if (r < l) break;
            cout << r << " ";
            r--;
        }
        if (l > r) break;
        cout << l << " ";
        l++;
    }
    cout << "\n";
 
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