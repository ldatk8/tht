/**
 *    author : Lăng Trọng Đạt
 *    created: 18-06-2024 
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
 
struct Dinic {
    struct Edge {
        int to, rev;
        int flow, cap;
    };

    const bool SCALING = true;
    int lim = 1;
    int n, m, source, sink;
    vector<int> lev, ptr;
    vector<vector<Edge>> adj;
    
    void add_edge(int a, int b, int cap, bool isDirected = true) {
        adj[a].push_back({b, adj[b].size(), 0, cap});
        adj[b].push_back({a, adj[a].size() - 1, 0, (isDirected ? 0 : cap)});
    }    
    void init() {
        cin >> n >> m;
        lev = ptr = vector<int>(n + 1);
        adj.resize(n + 1);
        source = 1, sink = n;
        FOR(i, 1, m) {
            int a, b, c;
            cin >> a >> b >> c;
            add_edge(a, b, c, false);
        }
    }

    int calc() {
        int max_flow = 0, flow;
        for (lim = (SCALING ? 1 << 30 : 1); lim > 0; lim /= 2) {
            while (bfs(source)) {
                fill(ptr.begin(), ptr.end(), 0);
                while (flow = dfs(source, INF)) {
                    max_flow += flow;
                }
            }
        }
        return max_flow;
    }
    bool bfs(int s) {
        fill(lev.begin(), lev.end(), -1);
        lev[s] = 0;
        queue<int> q;
        q.push(s);
        while (si(q)) {
            int v = q.front();
            q.pop();
            for (Edge &e : adj[v]) {
                if (lev[e.to] == -1 && e.cap - e.flow >= lim) {
                    lev[e.to] = lev[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return lev[sink] != -1;
    }
    
    int dfs(int v, int pushed) {
        if (v == sink or pushed == 0) return pushed;
        for (; ptr[v] < adj[v].size(); ptr[v]++) {
            Edge& e = adj[v][ptr[v]];
            if (lev[e.to] != lev[v] + 1 or e.cap - e.flow == 0) continue;
            int flow = dfs(e.to, min(pushed, e.cap - e.flow));
            if (flow != 0) {
                e.flow += flow;
                adj[e.to][e.rev].flow -= flow;
                return flow;
            }
        }
        return 0;
    }
};

/*
    * Fast flow using Dinic algorithm with scaling
    * Source: https://codeforces.com/blog/entry/66006
    * Verification: https://www.spoj.com/status/FASTFLOW,no_love_25/
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
    //    freopen("hi.out", "w", stderr);
    } 
 
    Dinic d;
    d.init();
    cout << d.calc();
 
}
