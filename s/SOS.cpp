/**
 *    author : Lăng Trọng Đạt
 *    created: 17-06-2024 
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

const int MAXN = (1 << 22) + 10;
int g[MAXN];
int a[MAXN];
int n;

int f[MAXN]; // f[mask]: number of submask of mask in given number
int f2[MAXN];
/*
    Description: Subset over subset
    Time: O(N * 2^N) (N là bit lớn nhất trong các số đã cho) 
    Source: https://codeforces.com/blog/entry/45223
    Vertification: https://cses.fi/problemset/result/9567959/
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    cin >> n;
    FOR(i, 1, n) {
        cin >> g[i];
        f[g[i]]++;
        f2[g[i]]++;
    }   

    FOR(i, 0, 22) {
        for (int mask = 1; mask < MAXN; mask++)
            if ((1 << i) & mask) {
                f[mask] += f[mask ^ (1 << i)];
            }
        for (int mask = MAXN - 1; mask > 0; mask--) {
            if ((1 << i) & mask) {
                f2[mask ^ (1 << i)] += f2[mask];
            }
        }
    }
    FOR(i, 1, n) {
        int mask = 0;
        FOR(j, 0, 20) {
            if (!((1 << j) & g[i])) {
                mask += 1 << j;
            }   
        }
        // db(bitset<20>(g[i]))
        // db(mask, bitset<20>(mask))
        cout << f[g[i]] << " " << f2[g[i]] << " " << n - f[mask] << "\n";
    }
}