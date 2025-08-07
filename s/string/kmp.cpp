/**
 *    author : Lăng Trọng Đạt
 *    created: 26-07-2025 
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
const int MOD = 111539786;

const int N = 1e6 + 5;
int g[N];
int n, m, k, q, a, b, c;

struct KMP
{
    vector<int> pi;
    string s;
    void init(string t) {
        s = t;
        pi.resize(si(s));
        FOR(i, 1, si(s) - 1) {
            pi[i] = nxt(pi[i - 1], t[i]);
        }
    }
    int nxt(int i, char c) {
        while (i > 0 && s[i] != c) {
            i = pi[i - 1];
        }
        return i + (c == s[i]);
    }
} kmp;

void add(int& a, int b) {
    a = (a + (b % MOD)) % MOD;
}
int dp[N][6];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    string p;
    cin >> n >> p;
    kmp.init(p);

    dp[0][0] = 1;
    // dp[i][j]: xét xâu độ dài i, với j kí tự cuối cùng trùng với j kí tự đầu tiên của p
    FOR(i, 1, n) {
        FOR(j, 0, si(p) - 1) {
            add(dp[i][kmp.nxt(j, '0')], dp[i - 1][j]);
            add(dp[i][kmp.nxt(j, '1')], dp[i - 1][j]);
        }
    }
    
    int ans = 0;
    FOR(j, 0, si(p) - 1) {
        db(j, kmp.nxt(j, '0'), kmp.nxt(j, '1'))
        add(ans, dp[n][j]);
    }

    cout << ans;
}