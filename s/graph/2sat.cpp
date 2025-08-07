/**
 *    author : Lăng Trọng Đạt
 *    created: 27-07-2025 
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
#define FD(i, lo, up) for (int i = (up); (i) >= (lo); i--)
#define si(x) (int)(x.size())
bool mx(int& a, int b) { if (b > a) {a = b; return true;} return false;}
bool mi(int& a, int b) { if (b < a) {a = b; return true;} return false;}
using pii = pair<int, int>;
using vi = vector<int>;
const int INF = 1e18 + 5;
const int MOD = 1e9 + 7;

const int N = 1e6 + 5;
int s[N];
int n, m, k, q, a, b, c;

vector<int> nxt[N];
int low[N], id[N], comp[N], timer = 0, comp_cnt = 0;
bool in_queue[N];
vector<int> path;
void scc(int v) {
    path.push_back(v);
    id[v] = low[v] = ++timer;
    for (int u : nxt[v]) {
        if (comp[u]) continue;
        if (id[u]) mi(low[v], id[u]);
        else {
            scc(u); mi(low[v], low[u]);
        }
    }

    // db(v, id[v], low[v])
    if (id[v] == low[v]) {
        // db(v, comp_cnt, path)
        // db(nxt[v])
        comp[v] = ++comp_cnt;
        while (path.back() != v) {
            comp[path.back()] = comp_cnt;
            path.pop_back();
        }
        path.pop_back();
    }
}

/*
    2SAT problem
    https://cses.fi/problemset/result/13881596/
    https://cp-algorithms.com/graph/2SAT.html#algorithm
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    cin >> n >> m;

    FOR(i, 1, n) {
        char t1, t2;
        cin >> t1 >> a >> t2 >> b;
        // add(a + m * (t1 == '-'), b + m * (t2 == '-'));
        a = 2*a ^ (t1 == '+');
        b = 2*b ^ (t2 == '+');
        nxt[a ^ 1].push_back(b);
        nxt[b ^ 1].push_back(a);
    }

    FOR(i, 2, 2*m + 1) {
        for (int j : nxt[i]) db(i, j)
        if (!id[i]) {
            scc(i);
        }
    }
    for (int i = 2; i <= 2*m; i += 2) {
        db(i / 2, comp[i], comp[i + 1])
        if (comp[i] == comp[i + 1]) {
            cout << "IMPOSSIBLE";
            return 0;
        } else {
            s[i / 2] = comp[i] > comp[i + 1];
            // NOTE: I think it is not correct, but anywhere, it AC
        }
    }

    FOR(i, 1, m) {
        cout << (s[i] ? '+' : '-') << " ";
    }
}