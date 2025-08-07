/**
 *    author : Lăng Trọng Đạt
 *    created: 10-06-2024 
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
vi adj[MAXN], radj[MAXN];
int n, m, a, b;

vi order;
bool vis[MAXN];
void dfs(int v) {
    vis[v] = 1;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u);
    }
    order.pb(v);
}
int comp[MAXN];
void dfs2(int v, int c) {
    comp[v] = c;
    for (int u : radj[v]) {
        if (!comp[u])
            dfs2(u, c);
    }
}
/*
    Finding all strongly connected components using two dfs 
    Time: O(n + m)
    Source: Competitive Programmer’s Handbook (chapter 17/page 167)
    Verfication: https://cses.fi/problemset/result/9505272/
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    cin >> n >> m;
    FOR(i, 1, m) {
        cin >> a >> b;
        adj[a].pb(b);
        radj[b].pb(a);
    }
    FOR(i, 1, n) {
        if (!vis[i]) dfs(i);
    }
    int comp_cnt = 0;
    for (int i = si(order) - 1; i >= 0; i--) {
        if (!comp[order[i]]) dfs2(order[i], ++comp_cnt);
    }
    cout << comp_cnt << "\n";
    db(order)
    FOR(i, 1, n) {
        cout << comp[i] << " ";
    }
}