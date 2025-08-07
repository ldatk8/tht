/**
 *    author : Lăng Trọng Đạt
 *    created: 08-06-2024 
**/
#include <bits/stdc++.h>
using namespace std;
#ifndef LANG_DAT
#define db(...) ;
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

const int MAXN = 1e6 + 5;
int g[MAXN];
vi adj[MAXN];
int n, m, a, b;

int id[MAXN], low[MAXN];
vi path;
int timer = 1;
vector<vi> comp;
void dfs(int v, int prv) {
    id[v] = low[v] = timer++;
    path.push_back(v);
    bool multi_edges = false;
    for (auto u : adj[v]) {
        if (u == prv && !multi_edges) {
            multi_edges = true;
            continue;
        }
        else if (id[u]) mi(low[v], id[u]);
        else {
            dfs(u, v);
            mi(low[v], low[u]);
        }
    }
    if (id[v] == low[v]) { // v is down node of bridge
        comp.pb({v});
        while (path.back() != v) {
            comp.back().pb(path.back());
            path.pop_back();
        }
        path.pop_back();
    }
}
/*
    Two-Edge-Connected Components
    https://cp-algorithms.com/graph/bridge-searching.html
    https://usaco.guide/adv/BCC-2CC?lang=cpp#2-edge-connected-components
    https://judge.yosupo.jp/problem/two_edge_connected_components
    https://judge.yosupo.jp/submission/213668
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 
    cin >> n >> m;
    FOR(i, 1, m)  {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    FOR(i, 0, n - 1) {
        if (!id[i]) {
            dfs(i, -1);
        }
    }
    cout << si(comp);
    for (vi v : comp) {
        cout << "\n" << si(v) << " ";
        for (int i : v) cout << i << " "; 
    }
}