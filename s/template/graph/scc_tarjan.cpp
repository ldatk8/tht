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
vi adj[MAXN];
int n, m, a, b;

vi order;
int comp[MAXN], comp_cnt = 0;
int id[MAXN], low[MAXN], timer = 1;
vi path;
void dfs(int v) {
    id[v] = low[v] = timer++;
    path.pb(v);
    for (int u : adj[v]) {
        if (comp[u]) continue;
        if (id[u]) mi(low[v], id[u]);
        else {
            dfs(u);
            mi(low[v], low[u]);
        }
    }
    if (low[v] == id[v]) {
        comp[v] = ++comp_cnt;
        while (path.back() != v) {
            comp[path.back()] = comp_cnt;
            path.pop_back();
        }
        path.pop_back();
    }
}
/*
    Finding all strongly connected components using tarjan's algorithms, which use less memory (don't store r_adj) 
    Time: O(n + m)
    Source: https://usaco.guide/adv/SCC?lang=cpp#solution-tarjans
    Verfication: https://cses.fi/problemset/result/9505671/
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
    }
    FOR(i, 1, n) {
        if (!id[i]) {
            dfs(i);
        }
    }
    cout << comp_cnt << "\n";
    FOR(i, 1, n) {
        cout << comp[i] << " ";
    }
}