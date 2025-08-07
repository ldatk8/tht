/**
 *    author : Lăng Trọng Đạt
 *    created: 07-11-2023 
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
using pii = pair<int, int>;
 
const int MAXN = 2e5 + 5;
int g[MAXN];
int n, q;
 
struct Segment_tree {
    vector<int> s_id;
    vector<pii> st;
    Segment_tree(bool sum_index) {
        s_id.resize(4*(n + 5));
        st.resize(4*(n + 5));
        build(sum_index);
    } 
    void build(bool sum_index, int v = 1, int l = 1, int r = n) {
        if (l == r) {
            s_id[v] = (sum_index ? l : 1);
        } else {
            int mid = (l + r) / 2;
            build(sum_index, 2*v + 1, l, mid);
            build(sum_index, 2*v + 2, mid + 1, r);
            s_id[v] = s_id[2*v + 1] + s_id[2*v + 2];
        }
    }
    void push(int v, int l, int r) {
        if (l < r) {
            st[2*v + 1].s += st[v].s;
            st[2*v + 2].s += st[v].s;
        }
        st[v].f += st[v].s * s_id[v];
        st[v].s = 0;
    }
    void upd(int x, int y, int val, int v = 1, int l = 1, int r = n) {
        push(v, l, r);
        if (l > y or x > r) return;
        else if (x <= l && r <= y) {
            st[v].s += val;
        } else {
            int mid = (l + r) / 2;
            upd(x, y, val, 2*v + 1, l, mid);
            upd(x, y, val, 2*v + 2, mid + 1, r);
            push(2*v + 1, l, mid);
            push(2*v + 2, mid + 1, r);
            st[v].f = st[2*v + 1].f + st[2*v + 2].f;
        }
    }
    int get(int x, int y, int v = 1, int l = 1, int r = n) {
        push(v, l, r);
        if (l > y or x > r) return 0;
        else if (x <= l && r <= y) {
            return st[v].f;
        } else {
            int mid = (l + r) / 2;
            return  get(x, y, 2*v + 1, l, mid) + 
                    get(x, y, 2*v + 2, mid + 1, r);
        }
    }
};
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
        freopen("hi.txt", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 
 
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        g[i] += g[i - 1];
    }
    Segment_tree sum_id(true), tru(false);
    int type, a, b;
    while (cin >> type >> a >> b) {
        if (type == 1) {
            tru.upd(a, b, 1 - a);
            sum_id.upd(a, b, 1);
        } else {
            cout << g[b] - g[a - 1] + sum_id.get(a, b) + tru.get(a, b) << "\n";
        }
    }
 
}
//https://cses.fi/problemset/task/1736/