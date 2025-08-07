/**
 *    author : Lăng Trọng Đạt
 *    created: 06-06-2024 
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
int process[MAXN], deg[MAXN];
// process[v]: number of out edges which is in circuit
vector<pii> adj[MAXN];
int n, m, a, b;
bool in_circuit[MAXN];

vi path;
void dfs(int v) {
    while (si(adj[v])) {
        auto[u, id] = adj[v].back();
        adj[v].pop_back();
        if (in_circuit[id]) continue;
        in_circuit[id] = true;
        dfs(u);
    }
    path.pb(v);
}
/*
    * finding eulerian circuit in undirected graph
    * O(m)
    * verification: https://cses.fi/problemset/result/9465490/
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
        adj[a].pb({b, i});
        adj[b].pb({a, i});
        deg[a]++;
        deg[b]++;
    }   
    FOR(i, 1, m) if (deg[i] & 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    dfs(1);
    if (si(path) == m + 1) {
        for (int i : path) cout << i << " ";
    } else {
        cout << "IMPOSSIBLE";
    }
}