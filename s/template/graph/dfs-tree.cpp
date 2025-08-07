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
pii ans[MAXN];
vector<pii> adj[MAXN];
int n, m, a, b;

// for finding bridge, if this graph have bridge answer will be no
int dp[MAXN]; // dp[u]: number back edge passing over the edge between u and its parent
// dp[u] = #back-edges go up from u - #back-edges go down from u + dp[v] (v is child of u)
// dp[u] = 0 mean the edge between u and its parent is bridge
bool vis[MAXN], use[MAXN];
void dfs(int v) {
    vis[v] = 1;
    for (auto[u, id] : adj[v]) {
        if (use[id]) continue;
        use[id] = true;
        if (vis[u]) { // this edge is back-edge go down from u to v,
            // so it will directed go up (in res graph)
            dp[v]++;
            dp[u]--;
            ans[id] = {v, u};
        } else { // this edge is span-edge
            dfs(u);
            ans[id] = {v, u};
            dp[v] += dp[u];
            // cout << v << " " << u << "\n"; // if you want to see spaning tree
        }
    }
}

/*
    finding bridge and re directed all edge in O(m)
    https://codeforces.com/blog/entry/68138
    https://codeforces.com/contest/118/submission/264661135
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
    }   

    dfs(1);
    bool have_bridge = false;
    FOR(i, 2, n) { // don't count root node
        if (dp[i] == 0) {
            have_bridge = true;
        }
    }

    if (have_bridge) {
        cout << 0;
    } else {
        FOR(i, 1, m) {
            cout << ans[i].f << " " << ans[i].se << "\n";
        }
    }
}