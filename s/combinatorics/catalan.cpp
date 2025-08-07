/**
 *    author : Lăng Trọng Đạt
 *    created: 15-09-2024 
**/
#include <bits/stdc++.h>
using namespace std;
#ifndef LANG_DAT
#define db(...) ;
#endif // LANG_DAT
#define int int64_t
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); (i) <= (b); (i++))
#define si(x) (int)(x.size())
void inline mx(int& a, int b) { if (b > a) a = b; }
void inline mi(int& a, int b) { if (b < a) a = b; }
using pii = pair<int, int>;

int c[20];

const int MAX = 35;
const int MOD = 1e9 + 7;
int poww(int p, int e) {
    int res = 1;
    while (e > 0) {
        if (e & 1) res = (res * p) % MOD;
        e /= 2;
        p = (p * p) % MOD;
    }
    return res;
}
int fac[MAX], inv[MAX], mau_so[MAX];

int mul(int a, int b) {
    return (a % MOD) * (b % MOD) % MOD;
}
int catalan(int x) {
    return mul(mul(fac[2*x], mul(inv[x], inv[x])), mau_so[x + 1]);
}
void init() {
    fac[0] = fac[1] = 1;
    FOR(i, 1, MAX - 1) {
        fac[i] = (fac[i - 1] * i) % MOD;
        inv[i] = poww(fac[i], MOD - 2);
        mau_so[i] = poww(i, MOD - 2);
        db(i, fac[i], inv[i])
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    init();
    FOR(i, 1, 15) {
        db(i, catalan(i))
    }
}

// 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 207936, 742900, 2674440







