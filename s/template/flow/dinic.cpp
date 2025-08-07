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

const int MAXN = 500 + 5;
vector<vector<int>> adj, capacity;
vector<int> ptr, lev;
int n, m, k;
int source, sink;

bool bfs() {
    fill(all(lev), -1);
    lev[source] = 0;
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (lev[u] == -1 && capacity[v][u]) {
                lev[u] = lev[v] + 1;
                q.push(u);
            }
        }
    }

    return lev[sink] != -1;
}

int dfs(int v, int flow) {
    if (v == sink) return flow;

    for (; ptr[v] < adj[v].size(); ptr[v]++) {
        int u = adj[v][ptr[v]];
        if (lev[u] == lev[v] + 1 && capacity[v][u]) {
            int new_flow = dfs(u, min(flow, capacity[v][u]));
            if (new_flow != 0) {
                capacity[v][u] -= new_flow;
                capacity[u][v] += new_flow;
                return new_flow;
            } 
        }
    }

    return 0;
}
/*
    * Fiding maximum flow using Dinic algorithms
    * It runtime in unit network (i.e bipartite graph) is O(sqrt(V) * E) 
    * (But partice runtime is slower than edmond-karp)
    * Source: https://cp-algorithms.com/graph/dinic.html
    * Verification: https://cses.fi/problemset/result/9581825/
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    cin >> n >> m >> k;
    source = 0;
    sink = n + m + 1;
    adj = capacity = vector<vector<int>>(sink + 1, vector<int>(sink + 1));
    
    FOR(i, 1, k) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b + n);
        adj[b + n].push_back(a);
        capacity[a][b + n]++;
    }    
    FOR(i, 1, n) {
        adj[source].push_back(i);
        adj[i].push_back(source);
        capacity[source][i]++;
    }
    FOR(i, 1, m) {
        adj[i + n].push_back(sink);
        adj[sink].push_back(i + n);
        capacity[i + n][sink]++;
    }

    auto temp = capacity;
    ptr.resize(sink + 1);
    lev.resize(sink + 1);
    int max_flow = 0, new_flow;

    while (bfs()) {
        fill(all(ptr), 0);
        while (new_flow = dfs(source, INF)) {
            max_flow += new_flow;
        }
    }

    cout << max_flow << "\n";
    FOR(i, 1, n)
        FOR(j, 1, m)
            if (capacity[i][j + n] != temp[i][j + n]) {
                cout << i << " " << j << "\n";
            }
}