/**
 *    author : Lăng Trọng Đạt
 *    created: 12-07-2024 
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

const int MAXN = 1e5 + 5;
const int K = 200;
vector<int> adj[MAXN];
int g[MAXN], hi[MAXN];
int n, q, a, b;

int node[2*MAXN], in[MAXN], out[MAXN], timer = 0, d[MAXN];
int lca_timer = 0, in_lca[MAXN];
int rmq[20][2*MAXN];
void dfs(int v, int prv) {
    in[v] = ++timer;
    node[timer] = v;
    in_lca[v] = ++lca_timer;
    rmq[0][lca_timer] = v;
    for (int u : adj[v]) {
        if (u == prv) continue;
        d[u] = d[v] + 1;
        dfs(u, v);
        rmq[0][++lca_timer] = v;
    }
    out[v] = ++timer;
    node[timer] = v;
}

int minn(int a, int b) {
    return (d[a] < d[b] ? a : b);
}

void init() {
    cin >> n >> q;
    vector<int> nums;
    FOR(i, 1, n) {
        cin >> hi[i];
        nums.push_back(hi[i]);
    }
    sort(all(nums));
    nums.resize(unique(all(nums)) - nums.begin());
    FOR(i, 1, n) {
        g[i] = lower_bound(all(nums), hi[i]) - nums.begin();
    }
    FOR(i, 1, n - 1) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    FOR(log, 1, 19) {
        FOR(i, 1, lca_timer - (1 << (log - 1))) {
            rmq[log][i] = minn(rmq[log - 1][i], rmq[log - 1][i + (1 << (log - 1))]);
        }
    }
}

int get_lca(int u, int v) {
    if (in_lca[v] < in_lca[u]) swap(u, v);
    int len = in_lca[v] - in_lca[u];
    int log = 31 - __builtin_clz(len);
    return minn(rmq[log][in_lca[u]], rmq[log][in_lca[v] - (1 << log) + 1]);
}

int lca_val[MAXN], ans[MAXN], cnt[MAXN], cnt_occur[MAXN];
vector<array<int, 3>> querys;
void mo() {
    sort(all(querys), [](array<int, 3>& a, array<int, 3>& b) -> bool {
        if (a[0] / K != b[0] / K) return a[0] < b[0];
        else if (a[0] / K % 2 == 0) return a[1] < b[1];
        else return a[1] > b[1];
    });

    int l = 1, r = 0, res = 0;

    auto change = [&](int v, int type) {
        cnt_occur[v] += type;
        if (cnt_occur[v] % 2 == 0) {
            cnt[g[v]]--;
            if (cnt[g[v]] == 0) res--;
        } else {
            if (cnt[g[v]] == 0) res++;
            cnt[g[v]]++;
        } 
    };

    for (auto[a, b, id] : querys) {
        while (r < b) change(node[++r], 1);
        while (r > b) change(node[r--], -1);
        while (l > a) change(node[--l], 1);
        while (l < a) change(node[l++], -1);

        ans[id] = res;
        if (lca_val[id] != -1 && cnt[lca_val[id]] == 0) ans[id]++;
    }
}
/*
    * Mo on tree
    * Source: https://codeforces.com/blog/entry/43230
    * Verification: https://www.spoj.com/submit/COT2/id=33299419
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
       freopen("hi.out", "w", stdout);
    } 

    memset(lca_val, -1, sizeof(lca_val));
    init();

    FOR(i, 1, q) {
        cin >> a >> b;
        if (in[a] > in[b]) swap(a, b);
        int lca = get_lca(a, b);
        lca_val[i] = g[lca];
        if (a == lca) 
            querys.push_back({in[a], in[b], i});
        else querys.push_back({out[a], in[b], i});
    }

    mo();

    FOR(i, 1, q) {
        cout << ans[i] << "\n";
    }
}
