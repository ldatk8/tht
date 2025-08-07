/**
 *    author : Lăng Trọng Đạt
 *    created: 21-05-2024 
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

const int MAXN = 2e5 + 5;
int g[MAXN];
vi adj[MAXN];
int n, q, l, r;

int far[MAXN], lca[MAXN], d[MAXN];
int get(int v) { return far[v] == 0 ? v : far[v] = get(far[v]); }
vector<pii> query[MAXN];
bool vis[MAXN];
void tarjan(int v, int prv, int dist) {
    vis[v] = true;
    d[v] = dist;
    for (int u : adj[v]) {
        if (u == prv) continue;
        tarjan(u, v, dist + 1); 
        far[u] = v;
    }
    for (auto[u, id] : query[v]) {
        if (vis[u]) lca[id] = get(u);
    }
}
// Tarjan's Offline LCA algorithm
// https://cses.fi/problemset/result/9311938/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
        freopen("hi.txt", "r", stdin);
       freopen("hi.out", "w", stdout);
    } 

    cin >> n >> q;
    FOR(i, 1, n - 1) {
        cin >> l >> r;
        adj[l].pb(r);
        adj[r].pb(l);
    }


    vector<pii> Q;
    FOR(i, 1, q) {
        cin >> l >> r;
        query[l].pb({r, i});
        query[r].pb({l, i});
        Q.pb({l, r});
    }
    tarjan(1, -1, 1);
    FOR(i, 1, q) {
        cout << d[Q[i - 1].f] + d[Q[i - 1].se] - 2*d[lca[i]] << "\n";
    }
}