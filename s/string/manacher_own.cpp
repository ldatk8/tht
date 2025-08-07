/**
 *    author : Lăng Trọng Đạt
 *    created: 15-06-2025 
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
#define all(v) (v).begin(), (v).finish()
#define FOR(i, a, b) for (int i = (a); (i) <= (b); (i++))
#define FD(i, lo, up) for (int i = (up); (i) >= (lo); i--)
#define si(x) (int)(x.size())
bool mx(int& a, int b) { if (b > a) {a = b; return true;} return false;}
bool mi(int& a, int b) { if (b < a) {a = b; return true;} return false;}
using pii = pair<int, int>;
using vi = vector<int>;
const int INF = 1e18 + 5;
const int MOD = 51123987;

const int N = 2e6 + 5;
int g[N], ans = 0;
int n, m, k, q, a, b, c;

int start[N], finish[N];
void add(int& a, int b) {
    a = (a + (b % MOD)) % MOD;
}
int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int le[N], chan[N], r[2*N];
void manacher(string s) {
    /*
        s will be 1-indexed
        ĐPT: O(N)
        le[i]: vị trí bên trái cùng của palindrome có tâm tại i
        chan[i]: vị trí bên trái cùng của palin có tâm giữa i với i + 1
    */
    string t = "";
    for (char c : s) {
        t.push_back(c);
        t.push_back('|');
    }

    for (int i = 1, cen = 0, id = 0; i < si(t); i++) {
        if (i <= cen + r[cen]) {
            r[i] = min(r[cen - (i - cen)], cen + r[cen] - i);
        }
        while (i + r[i] + 1 < si(t) && t[i + r[i] + 1] == t[i - r[i] - 1]) r[i]++;
        if (r[i] > r[cen]) cen = i;

        id += t[i] != '|';
        if (i % 2 == 0) {
            le[id] = id - r[i] / 2;
        } else {
            chan[id] = id - r[i] / 2 + 1;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    string s;
    cin >> n >> s;
    s = '#' + s;

    // bước 1: tại mỗi vị trí, tìm cái palindrom dài nhất mà chỗ đó là tâm
    // FOR(i, 1, n) {
    //         le[i] = chan[i] = i;
    //         while (le[i] >= 1 && s[le[i]] == s[i + i - le[i]]) le[i]--;
    //         while (chan[i] >= 1 && s[chan[i]] == s[i + i - chan[i] + 1]) chan[i]--;
    //         le[i]++;
    //         chan[i]++;
    // }
    manacher(s);
    
    int palin = 0;
    FOR (i, 1, n) {
        int l = i - le[i] + 1; palin += l;
        start[le[i]]++; start[i + 1]--;
        finish[i]++; finish[i + i - le[i] + 1]--;

        if (chan[i] <= i) {
            int l = i - chan[i] + 1; palin += l;
            start[chan[i]]++; start[i + 1]--;
            finish[i + 1]++; finish[i + i - chan[i] + 1 + 1]--;
        }
    }

    
    for (int sum = 0, i = 1; i <= n; i++) {
        add(start[i], start[i - 1]);
        add(finish[i], finish[i - 1]);

        add(ans, sum * start[i]);
        add(sum, finish[i]);
    }

    a = palin, b = palin - 1;
    if (a % 2 == 0) a /= 2;
    else b /= 2;
    cout << (mul(a, b) - ans + MOD) % MOD;
}