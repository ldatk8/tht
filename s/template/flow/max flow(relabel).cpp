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
vector<vi> capacity, flow;
vector<int> excess, height;
vector<int> excess_vertexes;
int g[MAXN];
int n, m;

void push(int u, int v) {
    int d = min(excess[u], capacity[u][v] - flow[u][v]);
    excess[u] -= d;
    excess[v] += d;
    
    flow[u][v] += d;
    flow[v][u] -= d;

    if (excess[v] == d && d) excess_vertexes.push_back(v);
}
void push_excess(int u) {
    for (int v = 1; excess[u]; v++) {
        if (v == n + 1) {
            v = 0;
            int d = INF;
            FOR(i, 1, n) {
                if (capacity[u][i] > flow[u][i]) 
                    mi(d, height[i]);
            }
            if (d != INF) height[u] = d + 1;
        } else if (height[u] > height[v]) {
            push(u, v);
        }
    }
}
/*
    * Finding max flow using Push-Relabel algorithm
    * Source: https://usaco.guide/adv/max-flow?lang=cpp#push-relabel-algorithm
    * Verification
    * Time: O(n^2 * m)
    * Important note: heigh is use to make sure some node don't excess to 
    * previous of it (in the first round)
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    cin >> n >> m;
    capacity = flow = vector<vi>(n + 1, vector<int>(n + 1));
    excess = height = vector<int>(n + 1);

    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        capacity[a][b] += c;
    }

    int source = 1, sink = n;
    height[source] = n;
    excess[source] = INF;
    
    FOR(i, 1, n) {
        if (i != source)
            push(source, i);
    }

    while (!excess_vertexes.empty()) {
        int v = excess_vertexes.back();
        excess_vertexes.pop_back();
        if (v != source && v != sink)
            push_excess(v);
    }

    int max_flow = 0;
    FOR(i, 1, n) {
        max_flow += flow[i][sink];
    }

    cout << max_flow;
}