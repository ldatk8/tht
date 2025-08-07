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
bool mx(int& a, int b) { if (b > a) {a = b; return true;} return false;}
bool mi(int& a, int b) { if (b < a) {a = b; return true;} return false;}
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 1e18 + 5;
const int MOD = 1e9 + 7;

const int N = 1e6 + 5;
int g[N];
int num_test, n, m, k, q, a, b, c;



bool LangDatPBC() {
    

    return true;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    num_test = 1;
    cin >> num_test;
    FOR(test, 1, num_test) {
        cout << (LangDatPBC() ? "\n" : "-1\n");
    }

}