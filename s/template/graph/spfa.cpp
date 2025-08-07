/**
 *    author : Lăng Trọng Đạt
 *    created: 05-06-2024 
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

const int MAXN = 2000 + 5;
vector<pii> adj[MAXN];
vi d;
int n, m, s, Q, a, b, w, v;
bool is_inf_len[MAXN];
void dfs(int v) {
    if (is_inf_len[v]) return;
    is_inf_len[v] = true;
    for (auto[u, w] : adj[v]) {
        if (!is_inf_len[u]) {
            dfs(u);
        }
    }
} 
// https://open.kattis.com/submissions/13780477
// https://cp-algorithms.com/graph/bellman_ford.html#shortest-path-faster-algorithm-spfa
int p[MAXN];
void spfa() {
    vector<bool> in_queue(n + 1);
    vi cnt(n + 1);
    d = vi(n + 1, INF);
    queue<int> q;

    q.push(s);
    in_queue[s] = 1;
    d[s] = 0;

    while (si(q)) {
        int v = q.front();
        in_queue[v] = false;
        q.pop();
        for (auto[u, w] : adj[v]) {
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                p[u] = v;
                if (!in_queue[u]) {
                    if (++cnt[u] >= n) {
                        dfs(u);
                    } else {
                        in_queue[u] = true;
                        q.push(u);
                    }
                }
            }
        }
    }
}
vi find_cycle(int x) {
    // https://cses.fi/problemset/result/9458460/
    // x will be one of node in cycle or node can go from cycle
    vector<bool> vis(n + 1);
    vi cycle;
    for (int v = x;; v = p[v]) {
        cycle.pb(v);
        if (vis[v]) {
            db(v);
            break;
        }
        
        vis[v] = true;
    }
    reverse(all(cycle));
    while (cycle.back() != cycle[0]) cycle.pop_back();
    return cycle;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    while (cin >> n >> m >> Q >> s) {
        if (n == 0 && m == 0 && Q == 0 && s == 0) return 0;
        FOR(i, 0, n - 1) {
            is_inf_len[i] = 0;
            adj[i].clear();
        }
        FOR(i, 1, m) {
            cin >> a >> b >> w;
            adj[a].pb({b, w});
        }

        spfa();

        FOR(i, 1, Q) {
            cin >> v;
            if (is_inf_len[v]) cout << "-Infinity\n";
            else if (d[v] >= INF) cout << "Impossible\n";
            else cout << d[v] << "\n";
        }
    }
    
}