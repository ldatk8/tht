/**
 *    author : Lăng Trọng Đạt
 *    created: 2024-09-03
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
#define FOR(i, a, b) for (int i = a; (i) <= (b); i++)
void mx(int& a, int b) { if (b > a) a = b; }
void mi(int& a, int b) { if (b < a) a = b; }
#define si(x) (int)(x.size())
const int INF = 1e18;
const int MOD = 1e9 + 7;

const int N = 2500 + 5;
int d[N], prv[N];
vector<pii> adj[N];
int n, m, k, a, b, c;

int last = -1;
int cnt[N];
void spfa(int s) {
    d[s] = cnt[s] = 0;

    queue<int> q;
    q.push(s);

    while (si(q)) {
        int v = q.front(); q.pop();
        if (last != -1) break;
        for (auto[u, w] : adj[v]) {
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                cnt[u] = cnt[v] + 1;
                prv[u] = v;
                q.push(u);
                if (cnt[u] >= n) {
                    last = u;
                }
            }
        }
    }

    if (last != -1) {
        db(last)
        cout << "YES\n";
        vector<bool> vis(n + 1, false);
        while (!vis[last]) {
            vis[last] = 1;
            last = prv[last];
        }
        vector<int> res = {last};
        int start = last;
        last = prv[last];
        db(start,last)
        while (last != start) {
            res.push_back(last);
            last = prv[last];
        }
        res.push_back(last);
        reverse(all(res));
        for (int i : res) cout << i << " ";
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    }

    cin >> n >> m;
    FOR(i, 1, m) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    FOR(i, 1, n) {
        d[i] = INF;
    }

    FOR(i, 1, n) {
        if (d[i] == INF) {
            spfa(i);
            if (last != -1) return 0;
        }
    }

    cout << "NO";
}
