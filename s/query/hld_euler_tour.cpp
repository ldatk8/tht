/**
 *    author : Lăng Trọng Đạt
 *    created: 03-08-2025 
**/
#include <bits/stdc++.h>
using namespace std;
#ifndef LANG_DAT
#define db(...) ;
#endif // LANG_DAT
// #define int long long
#define f first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); (i) <= (b); (i++))
#define FD(i, lo, up) for (int i = (up); (i) >= (lo); i--)
#define si(x) (int)(x.size())
bool mx(int& a, int b) { if (b > a) {a = b; return true;} return false;}
bool mi(int& a, int b) { if (b < a) {a = b; return true;} return false;}
using pii = pair<int, int>;
using vi = vector<int>;
const int INF = 2e9 + 5;
const int MOD = 1e9 + 7;

const int N = 1e5 + 5;
int g[N];
int n, m, k, q, a, b, c;

/// @brief Lazy Segment Tree
int st[N], lazy[N];
void push(int v = 1, int l = 1, int r = n) {
    st[v] += lazy[v];
    if (l != r) {
        lazy[2*v] += lazy[v];
        lazy[2*v + 1] += lazy[v];
    }
    lazy[v] = 0;
}
void upd(int p, int q, int val, int v = 1, int l = 1, int r = n) {
    push(v, l, r);
    if (p > r or l > q) return;
    else if (p <= l && r <= q) {
        lazy[v] += val;
    } else {
        int mid = (l + r) / 2;
        upd(p, q, val, 2*v, l, mid); upd(p, q, val, 2*v + 1, mid + 1, r);
        push(2*v, l, mid); push(2*v + 1, mid + 1, r);
        st[v] = max(st[2*v], st[2*v + 1]);
    }
}
int get(int p, int q, int v = 1, int l = 1, int r = n) {
    push(v, l, r);
    if (p > r or l > q) return -INF;
    else if (p <= l && r <= q) {
        return st[v];
    } else {
        int mid = (l + r) / 2;
        return max(get(p, q, 2*v, l, mid), get(p, q, 2*v + 1, mid + 1, r));
    }
}

/// @brief Heavy-Light Decomposition
vector<int> adj[N];
int sz[N], d[N], far[N], heavy[N];
void dfs_sz(int v) {
    sz[v] = 1;
    for (int u : adj[v]) {
        if (u == far[v]) continue;
        d[u] = d[v] + 1;
        far[u] = v;
        dfs_sz(u);
        sz[v] += sz[u];
        if (sz[u] > sz[heavy[v]]) heavy[v] = u;
    }
}

int head[N], id[N], in[N], out[N], timer = 0;
void hld(int v, int top) {
    if (v == 0) return;
    id[v] = ++timer;
    head[v] = top;
    hld(heavy[v], top);

    for (int u : adj[v]) {
        if (u == heavy[v] or u == far[v]) continue;
        hld(u, u);
    }
}

void init() {
    cin >> n;
    FOR(i, 1, n - 1) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_sz(1);
    hld(1, 1);

    FOR(i, 1, n) {
        db(i, d[i], sz[i], heavy[i], head[i], id[i])
    }
}

int qr(int a, int b) {
    int ans = -INF;
    while (head[a] != head[b]) {
        if (d[head[a]] > d[head[b]]) swap(a, b);
        mx(ans, get(id[head[b]], id[b]));
        b = far[head[b]];
    }

    if (id[a] > id[b]) swap(a, b);
    mx(ans, get(id[a], id[b])); 

    return ans;
}

void solve() {
    string type;
    cin >> q;
    FOR(i, 1, q) {
        cin >> type >> a >> b;
        if (type == "add") {
            upd(id[a], id[a] + sz[a] - 1, b);   
        } else {
            cout << qr(a, b) << "\n";
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    init();
    solve();

}