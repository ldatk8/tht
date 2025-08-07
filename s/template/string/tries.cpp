/**
 *    author : Lăng Trọng Đạt
 *    created: 21-06-2024 
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

const int MAXN = 1e6 + 5;
int nxt[MAXN][26];
bitset<MAXN> stop;
int n, m, sz = 0;
string s, t;

void insert(string& s) {
    int v = 0;
    for (char c : s) {
        if (!nxt[v][c - 'a']) nxt[v][c - 'a'] = ++sz;
        v = nxt[v][c - 'a'];
    }
    stop[v] = 1;
}

/*
    * Trie (for multiple string)
    * Time: O(n)
    * Verification: https://cses.fi/problemset/result/9610661/
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
        freopen("hi.txt", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    cin >> s >> n;
    FOR(i, 1, n) {
        cin >> t;
        insert(t);
    }

    n = si(s);
    vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        int v = 0;
        for (int j = i; j < n; j++) {
            if (!nxt[v][s[j] - 'a']) break;
            v = nxt[v][s[j] - 'a'];
            if (stop[v]) dp[i] = (dp[i] + dp[j + 1]) % MOD;
        }
    }

    cout << dp[0];
}