/**
 *    author : Lăng Trọng Đạt
 *    created: 07-05-2024 
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
int g[MAXN];
int n, q, a, b;

int mask[MAXN];
int dat[20][MAXN];
void build(int l, int r, int lv) {
    if (l == r) {
        dat[lv][l] = g[l];
    } else {
        int m = (l + r) / 2;
        dat[lv][m] = g[m];
        dat[lv][m + 1] = g[m + 1];
        mask[m + 1] ^= 1 << lv;
        for (int i = m - 1; i >= l; i--) dat[lv][i] = min(dat[lv][i + 1], g[i]);
        for (int i = m + 2; i <= r; i++) {
            mask[i] ^= 1 << lv; 
            dat[lv][i] = min(dat[lv][i - 1], g[i]);
        }
        build(l, m, lv + 1);
        build(m + 1, r, lv + 1);
    }

}

// online query in static array
// https://cses.fi/problemset/result/9198597/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    cin >> n >> q;
    FOR(i, 1, n) cin >> g[i];

    build(1, n, 0);
    FOR(i, 1, q) {
        cin >> a >> b;
        int lv = __builtin_ctz(mask[a] ^ mask[b]);
        if (a == b) cout << g[a] << "\n";
        else cout << min(dat[lv][a], dat[lv][b]) << "\n";
    }

}