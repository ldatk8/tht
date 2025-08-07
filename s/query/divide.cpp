/**
 *    author : Lăng Trọng Đạt
 *    created: 06-05-2024 
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

const int MAXN = 2e5 + 5;
int g[MAXN], ans[MAXN];
pii q[MAXN];
int n, Q;

int l_ans[MAXN], r_ans[MAXN];
void divi(int l, int r, vi& query) {
    if (query.empty()) return;
    if (l == r) {
        for (int i : query) ans[i] = g[q[i].f];
    } else {
        int m = (l + r) / 2;
        l_ans[m] = g[m];
        for (int i = m - 1; i >= l; i--) l_ans[i] = min(g[i], l_ans[i + 1]);

        r_ans[m + 1] = g[m + 1];
        FOR(i, m + 2, r) r_ans[i] = min(g[i], r_ans[i - 1]);

        vi todo[2];

        for (int i : query) {
            if (q[i].f <= m && m < q[i].se) ans[i] = min(l_ans[q[i].f], r_ans[q[i].se]);
            else todo[q[i].f > m].pb(i);
        }

        divi(l, m, todo[0]);
        divi(m + 1, r, todo[1]);
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
        freopen("hi.txt", "r", stdin);
        freopen("hi.out", "w", stdout);
    } 
    // https://cses.fi/problemset/result/9187006/
    cin >> n >> Q;
    FOR(i, 1, n) cin >> g[i];

    FOR(i, 1, Q) cin >> q[i].f >> q[i].se;

    vi query(Q);
    iota(all(query), 1);

    divi(1, n, query);

    FOR(i, 1, Q) {
        cout << ans[i] << "\n";
    }    
}