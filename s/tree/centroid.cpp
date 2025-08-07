/**
 *    author : Lăng Trọng Đạt
 *    created: 04-08-2025 
**/
#include <bits/stdc++.h>
using namespace std;
#ifndef LANG_DAT
#define db(...) ;
#endif // LANG_DAT
#define int long long
#define f first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); (i) <= (b); (i++))
#define FD(i, lo, up) for (int i = (up); (i) >= (lo); i--)
#define si(x) (int)(x.size())
bool mx(int& a, int b) { if (b > a) {a = b; return true;} return false;}
bool mi(int& a, int b) { if (b < a) {a = b; return true;} return false;}
using pii = pair<int, int>;
using vi = vector<int>;
const int INF = 1e18 + 5;
const int MOD = 1e9 + 7;

const int N = 1e6 + 5;
int g[N];
int n, m, k, q, a, b, c;

vector<int> adj[N];
vector<pii> ancestors[N];
int sz[N];
bool rm[N];
struct Centroid {
    int dfs_sz(int v, int prv) {
        sz[v] = 1;
        for (int u : adj[v]) {
            if (u == prv or rm[u]) continue;
            sz[v] += dfs_sz(u, v);
        }
        return sz[v];
    }
    int find_centroid(int v, int prv, int cur_sz) {
        for (int u : adj[v]) {
            if (u == prv or rm[u]) continue;
            if (2*sz[u] > cur_sz) return find_centroid(u, v, cur_sz);
        }   
        return v;
    }
    void dist_to_par(int v, int prv, int dist, int up) {
        ancestors[v].push_back({up, dist});
        for (int u : adj[v]) {
            if (u == prv or rm[u]) continue;
            dist_to_par(u, v, dist + 1, up);
        }
    }
    void build(int v) {
        int cen = find_centroid(v, -1, dfs_sz(v, -1));
        rm[cen] = 1;
        dist_to_par(cen, -1, 0, cen);
        for (int u : adj[cen]) {
            if (rm[u]) continue;
            build(u);
        }
    }
} cen;
/*
    Centroid Decomposition
    Verification: https://codeforces.com/contest/342/submission/332288251
    Source: https://medium.com/carpanese/an-illustrated-introduction-to-centroid-decomposition-8c1989d53308
    TC: O(nlog(n)) for build, because of high of centroid tree is log(n) due to size of children will be < sz(far) / 2
        O(log(n)) per query and update
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    cin >> n >> q;
    FOR(i, 1, n - 1) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    

    cen.build(1);

    vector<int> min_dist(n + 1, INF);
    for (auto[far, d] : ancestors[1]) {
        mi(min_dist[far], d);
    }
    
    FOR(i, 1, q) {
        cin >> a >> k;
        if (a == 1) {
            for (auto[far, d] : ancestors[k]) {
                mi(min_dist[far], d);
            }
        } else {
            int ans = INF;
            for (auto[far, d] : ancestors[k]) {
                mi(ans, d + min_dist[far]);
            }
            cout << ans << "\n";
        }
    }
}