/**
 *    author : Lăng Trọng Đạt
 *    created: 03-06-2024 
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
#define arr array<int, 4>
const int INF = 1e18;
const int MOD = 1e9 + 7;

const int MAXN = 3e5 + 5;
int g[MAXN];
int n, p;

bool solve() {
    cin >> n >> p;
    vector<arr> events;
    vi max_giam(p + 1);
    FOR(i, 1, p) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.pb({x1, y1, i, 1});
        events.pb({x2, y2, i, 0});
        max_giam[i] = x2 - x1 + y2 - y1;
    }    
    sort(all(events), [](array<int, 4>& a, array<int, 4>& b) -> bool {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] > b[0];
    });
    map<int, int> mp;
    mp[n] = 0;
    for (auto[x, y, i, type] : events) {
        auto giam = mp.lower_bound(y);
        if (type == 0) {
            max_giam[i] += giam->se;
        } else {
            mx(max_giam[i], giam->se);
            mp[y] = max_giam[i];
            auto it = mp.lower_bound(y);
            while (it != mp.begin() && prev(it)->se <= max_giam[i]) {
                mp.erase(prev(it));
            }
        }
    }
    cout << 2*n - mp.lower_bound(0)->se;
    return true;
}
/*
    * source: https://usaco.guide/adv/springboards?lang=cpp
    * verification: https://usaco.org/index.php?page=viewproblem2&cpid=995
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } else if(fopen("boards.inp", "r")){
        freopen("./boards.inp", "r", stdin);
        freopen("./boards.out", "w", stdout);
    } else if(fopen("boards.in", "r")){
        freopen("./boards.in", "r", stdin);
        freopen("./boards.out", "w", stdout);
    }


    int t = 1;
    //cin >> t;
    while (t--) {
        cout << (solve() ? "" : "");
    }

}
