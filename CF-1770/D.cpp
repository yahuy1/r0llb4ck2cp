#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
int n;
int a[100003];
int b[100003];
int par[100003];
int eCnt[100003];
int vCnt[100003];

int root(int u) {
    if (par[u] < 0) return u;
    return root(par[u]);
}

void merge(int u, int v) {
    if (root(u) == root(v)) {
        eCnt[root(u)]++;        
        return;
    }

    u = root(u);
    v = root(v);

    if (eCnt[u] < eCnt[v]) swap(u, v);

    par[v] = u;
    eCnt[u] += eCnt[v] + 1;

    return;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector <pair <int, int>> edge;

    memset(eCnt, 0, sizeof(eCnt));
    memset(vCnt, 0, sizeof(vCnt));
    for (int i = 1; i <= n; i++) {
        par[i] = -1;
        edge.push_back({a[i], b[i]});
    }    

    vector <vector<pair <int, int>>> rEdge(n + 1);
    for (pair <int, int> e : edge) {
        merge(e.first, e.second);
        rEdge[root(e.first)].push_back(e);
    }

    vector <int> roots;
    for (int i = 1; i <= n; i++) {
        vCnt[root(i)]++;
        if (root(i) == i) roots.push_back(i);
        else {
            for (pair <int, int> e : rEdge[i]) rEdge[root(i)].push_back(e);
        }
    }

    int ans = 1;
    for (int i : roots) {
        if (eCnt[i] != vCnt[i]) {
            cout << 0 << "\n";
            return;
        }
        
        bool self_loop = false;
        for (pair <int, int> e : rEdge[i]) {
            if (e.first == e.second) {
                self_loop = true;
                break;
            }
        }

        if (self_loop) {
            ans = ans * n % MOD;
        } else ans = ans * 2 % MOD;
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