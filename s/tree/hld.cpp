/**
 *    author : Lăng Trọng Đạt
 *    created: 27-05-2024 
**/
#include <bits/stdc++.h>
using namespace std;
#ifndef LANG_DAT
#endif // LANG_DAT
#define int long long
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
using pii = pair<int, int>;
using vi = vector<int>;
#define FOR(i, a, b) for (int (i) = a; (i) <= (b); i++)
void mx(int& a, int b) { if (b > a) a = b; }
void mi(int& a, int b) { if (b < a) a = b; }
#define si(x) (int)(x.size())
const int INF = 1e18;
const int MOD = 1e9 + 7;
 
const int MAXN = 2e5 + 5;
int g[MAXN];
int n, a, b, m;
vi adj[MAXN];
 
// segment tree (point update, range query)
int st[2*MAXN];
void upd(int x, int val) {
	st[x + n] = val;
	for (int v = (x + n) / 2; v > 0; v /= 2)
		st[v] = max(st[2*v], st[2*v + 1]);
}
void build() {
	for (int v = n - 1; v > 0; v--) {
		st[v] = max(st[2*v], st[2*v + 1]);
	}
}
int st_query(int l, int r) {
	int res = 0;
	for (l = (l + n), r = (r + n + 1); l < r; l /= 2, r /= 2) {
		if (l & 1) mx(res, st[l++]);
		if (r & 1) mx(res, st[--r]);
	}
	return res;
}

// heavy light decomposition
vi depth, sz, heavy, par;
void dfs_si(int v) {
    // determine which child is heavy child
    sz[v] = 1;
    for (auto u : adj[v]) {
        if (u == par[v]) continue;
        depth[u] = depth[v] + 1;
        par[u] = v;
        dfs_si(u);
        sz[v] += sz[u];
        if (sz[u] > sz[heavy[v]]) heavy[v] = u;
    }
}
vi head, pos;
int curr_pos = 0;
void decompose(int v, int h) {
    // find head of heavy path where vertex v is in
    // and pos in segment tree (of heavy path)
    pos[v] = curr_pos++;
    head[v] = h;
    if (heavy[v]) {
        decompose(heavy[v], h);
    } 
    for (auto u : adj[v]) {
        if (u != par[v] && u != heavy[v]) {
            decompose(u, u);
        }
    }
}
int query(int a, int b) {
    int res = 0;
    while (head[a] != head[b]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        mx(res, st_query(pos[head[b]], pos[b]));
        b = par[head[b]];
    }
    if (pos[a] > pos[b])
        swap(a, b);
    int last_heavy_path = st_query(pos[a], pos[b]);
    mx(res, last_heavy_path);
    return res;
}
void init() {
    cin >> n >> m;
    FOR(i, 1, n) { cin >> g[i]; }
    FOR(i, 1, n - 1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    sz = depth = heavy = par = head = pos = vi(n + 1);
    dfs_si(1);
    decompose(1, 1);
    FOR(i, 1, n) {
		st[pos[i] + n] = g[i];
    }
	build();
}
/*
    Heavy-Light decomposition
    Query in O(log^2n) per query
    TC: O((N + M) * log^2(n))
    Verification:   
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
    } 
 
    init();

    // answer
    int type;
    while (cin >> type >> a >> b) {
        if (type == 1) {
            upd(pos[a], b);
        } else {
            cout << query(a, b) << " ";
        }
    }
}