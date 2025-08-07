/**
 *    author : Lăng Trọng Đạt
 *    created: 30-05-2024 
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


int mobius[MAXN]; // mobius[i] = 1 if i == 1, = 0 if i has a squared prime factor
                  // = (-1) ^ k if i is product of k distinct prime factor
void sieve() {
	mobius[1] = -1;
	for (int i = 1; i < MAXN; i++) {
		if (mobius[i]) {
			mobius[i] = -mobius[i];
			for (int j = 2*i; j < MAXN; j += i)
				mobius[j] += mobius[i];
		}
	}
}


int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    

}