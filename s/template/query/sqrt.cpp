/**
 *    author : Lăng Trọng Đạt
 *    created: 08-05-2024 
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
int n, q, l, r, k;
int sum[(int)sqrt(MAXN) + 2];

// https://cses.fi/problemset/result/9205418/
// square root algorithms
// O(1) / update
// O(sqrt(n)) / query
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
        if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
    //     freopen("hi.txt", "r", stdin);
    //    freopen("hi.out", "w", stdout);
    } 

    cin >> n >> q;
    FOR(i, 1, n) cin >> g[i];

    int k = sqrt(n) + 1;
    FOR(i, 1, n) 
        sum[i / k] += g[i];

    int type, pos, x, l, r;
    FOR(i, 1, q) {
        cin >> type;
        if (type == 1) {
            cin >> pos >> x;
            sum[pos / k] = sum[pos / k] + x - g[pos];
            g[pos] = x;
        } else {
            cin >> l >> r;
            int total = 0, first_block, last_block;
            while (l % k != 0 && l < r) {
                total += g[l++];
            }
            while (r % k != 0 && l < r) {
                total += g[r--];
            }
            total += g[r];
            for (int i = l + k - 1; i <= r; i += k) {
                total += sum[i / k];
            }
            cout << total << "\n";
        }
    }

}