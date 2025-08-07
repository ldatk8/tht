/**
 *    author : Lăng Trọng Đạt
 *    created: 13-06-2025 
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
const int INF = 1e18 + 5;
const int MOD = 1e9 + 7;

const int N = 20;
int g[N][N], ans[1 << N];
int n, m, k, q, a, b, c;


int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    cin >> n;
    FOR(i, 0, n - 1) FOR(j, 0, n - 1) cin >> g[i][j];

    int all = (1 << n) - 1;
    FOR(mask, 1, all) {
        vector<int> pos;
        FOR(i, 0, n - 1) {
            if ((1 << i) & mask) {
                pos.push_back(i);
            }
        }
        FOR(i, 0, si(pos) - 1) FOR(j, i + 1, si(pos) - 1) ans[mask] += g[pos[i]][pos[j]];

        for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
            mx(ans[mask], ans[sub] + ans[sub ^ mask]);
        }   
    }

    cout << ans[all];
}