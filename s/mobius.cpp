/**
 *    author : Lăng Trọng Đạt
 *    created: 11-06-2025
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
#define FD(i, a, b) for (int i = (b); (i) >= (a); (i--))
#define si(x) (int)(x.size())
void inline mx(int& a, int b) { if (b > a) a = b; }
void inline mi(int& a, int b) { if (b < a) a = b; }
using pii = pair<int, int>;

const int INF = 1e18 + 5;
const int MOD = 1e9 + 7;

const int N = 1e7 + 5;
int g[N];
int num_test, n, m, k, q, a, b, c;

int u[N + 1];
void mobius() {
    u[1] = -1;
    FOR(i, 1, N) {
        if (u[i]) {
            u[i] = -u[i];
            for (int j = 2*i; j < N; j += i) u[j] += u[i];
        }
    }
}

bool LangDatPBC() {
    cin >> n;
    int sq = 0;
    for (int i = 2; i * i <= n; i++) {
        sq += u[i] * (n / (i * i));
    }

    db(n, sq)
    cout << n + sq;

    return true;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    mobius();

    num_test = 1;
    cin >> num_test;
    FOR(test, 1, num_test) {
        cout << (LangDatPBC() ? "\n" : "-1\n");
    }

}