/**
 *    author : Lăng Trọng Đạt
 *    created: 12-02-2024 
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MAXN = 2e5 + 5;
int g[MAXN];
int n;

class BIT {
private:
    int len;
    vector<int> bit;
public:
    BIT(int size) : len(size), bit(size + 10) {}
    int get(int p) { // 1-indexed
        int res = 0;
        for (; p > 0; p -= p & (-p)) res += bit[p];
        return res;
    }
    int upd(int pos, int val) {
        for (int p = pos; p <= len; p += p & (-p)) bit[p] += val;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    int t;
    cin >> t;
    while (cin >> n) {
        BIT bit(1e7 + 20);
        FOR(i, 1, n) cin >> g[i];
        ordered_set s;
        int res = 0;
        for (int i = n; i > 0; i--) {
            s.insert(g[i]);
            res += s.order_of_key(g[i]);
        }
        cout << res << "\n";
    }
}