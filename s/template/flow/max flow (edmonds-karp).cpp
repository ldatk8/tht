/**
 *    author : Lăng Trọng Đạt
 *    created: 17-06-2024 
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

const int MAXN = 500 + 5;
int capacity[MAXN][MAXN];
vector<int> adj[MAXN];
vector<int> par;
int n, m;

int bfs(int s, int t) {
    par = vector<int>(n + 1, -1);
    par[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        auto[v, flow] = q.front(); q.pop();

        for (int nxt : adj[v]) {
            if (par[nxt] == -1 && capacity[v][nxt]) {
                par[nxt] = v;
                int new_flow = min(flow, capacity[v][nxt]);
                if (nxt == t)
                    return new_flow;
                q.push({nxt, new_flow});
            }
        }
    }

    return 0;
}
/*
    * Finding maximum flow in directed weighted graph
    * Using Edonds-Karp algorihm (implementation of Ford-Fulkerson method)
    * Time: O(V*|E|^2)
    * Sources: https://cp-algorithms.com/graph/edmonds_karp.html#edmonds-karp-algorithm
               https://usaco.guide/adv/max-flow?lang=cpp#implementation
    * Vertification: https://cses.fi/problemset/result/9571431/
*/

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    cin >> n >> m;
    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        capacity[a][b] += c;
        adj[a].pb(b);
        adj[b].pb(a);
    }    

    int s = 1, t = n;
    int max_flow = 0, new_flow;
    while (new_flow = bfs(1, n)) {
        max_flow += new_flow;
        int curr = t;
        while (curr != s) {
            int prv = par[curr];
            capacity[prv][curr] -= new_flow;
            capacity[curr][prv] += new_flow;
            curr = prv;
        }
    }

    cout << max_flow;
}