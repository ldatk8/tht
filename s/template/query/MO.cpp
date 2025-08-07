/**
 *    author : LÄ�ng Trá»�ng Ä�áº¡t
 *    created: 12-05-2024 
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
 
const int MAXN = 3e4 + 5;
int g[MAXN], cnt[(int)(1e6) + 10];
int ans[(int)(2e5) + 6];
int n, Q, l, r;
 
struct Query {
    int l, r, id;
};
 
int curr_ans = 0;
void process(int val, int x) {
    curr_ans -= cnt[val] > 0;
    cnt[val] += x;
    curr_ans += cnt[val] > 0;
}
const int sz = sqrt(MAXN);
// https://www.spoj.com/status/DQUERY,no_love_25/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 
 
    cin >> n;
    FOR(i, 1, n) cin >> g[i];
    cin >> Q;
    vector<Query> q(Q);
    FOR(i, 0, Q - 1) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
 
    sort(all(q), [&](Query& a, Query& b) -> bool {
        if (a.l / sz != b.l / sz) return a.l < b.l;
        else if ((a.l / sz) & 1) return a.r > b.r;
        else return a.r < b.r;
    });
 
    int mo_right = 0, mo_left = 1;

    for (auto& x : q) {
        while (mo_right < x.r) process(g[++mo_right], +1);
        while (mo_right > x.r) process(g[mo_right--], -1);
        while (mo_left > x.l) process(g[--mo_left], +1);
        while (mo_left < x.l) process(g[mo_left++], -1);
 
        ans[x.id] = curr_ans;
    }
 
    FOR(i, 0, si(q) - 1) {
        cout << ans[i] << "\n";
    }
} 