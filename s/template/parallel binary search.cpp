/**
 *    author : Lăng Trọng Đạt
 *    created: 03-08-2024 
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

const int N = 3e5 + 5;
vector<int> have[N];
int from[N], to[N], val[N];
int need[N], res[N];
int n, len, k;

int bitt[N];
struct BIT {
    void upd(int l, int r, int val, int type) {
        upd(l, val * type);
        upd(r + 1, -val * type);
    }
    void upd(int pos, int val) {
        for (; pos <= len; pos += pos & -pos) bitt[pos] += val;
    }
    int get(int pos) {
        int res = 0;
        for (; pos > 0; pos -= pos & -pos) res += bitt[pos];
        return res;
    }
} bit;

void upd(int pos, int type) {
    if (from[pos] <= to[pos]) {
        bit.upd(from[pos], to[pos], val[pos], type);
    } else {
        bit.upd(from[pos], len, val[pos], type);
        bit.upd(1, to[pos], val[pos], type);
    }
}

void solve(int lo, int hi, vector<int> owner, int& pos) {
    if (owner.empty()) return;
     int mid = (lo + hi) / 2;
    while (pos < mid) {
        upd(++pos, 1);
    }
    while (pos > mid) {
        upd(pos--, -1);
    }

    vector<int> left, right;
    for (int who : owner) {
        int total = 0;
        for (int where : have[who]) {
            total += bit.get(where);
            if (total >= need[who]) {
                break;
            }
        }
        if (total >= need[who]) {
            res[who] = pos;
            left.push_back(who);
        } else {
            right.push_back(who);
        }
    }   

    owner.clear();

    if (lo < hi) {
        solve(lo, mid, left, pos);
        solve(mid + 1, hi, right, pos);
    }
}

/*
    * Parallel binary search
    * https://codeforces.com/blog/entry/45578
    * O(n*log(n)^2)
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
       freopen("hi.out", "w", stdout);
    } 

    cin >> n >> len;
    FOR(where, 1, len) {
        int who;
        cin >> who;
        have[who].push_back(where);
    }
    vector<int> owner(n);
    FOR(i, 1, n) {
        owner[i - 1] = i;
        cin >> need[i];
    }
    cin >> k;
    FOR(i, 1, k) {
        cin >> from[i] >> to[i] >> val[i];
    }

    int pos = 0;
    solve(1, k, owner, pos);

    FOR(i, 1, n) {
        if (res[i] == 0) cout << "NIE\n";
        else cout << res[i] << "\n";
    }

}