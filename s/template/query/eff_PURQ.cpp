/**
 *    author : Lăng Trọng Đạt
 *    created: 12-02-2024 
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

/*
    * Verification: https://cses.fi/problemset/task/1649
    * Description: 1D point update and range query
*/
template<class T> class Seg_Tree {
private:
    const T DEFAULT = INF;
    vector<T> st;
    int len;
public:
    Seg_Tree(int l) : len(l), st(2*l, DEFAULT) {
        FOR(i, len, 2*len - 1) {
            cin >> st[i];
        }
        for (int p = len - 1; p > 0; p--) { // O(len)
            st[p] = cb(st[2*p], st[2*p + 1]);
        }
    }
    T cb(T& a, T& b) { // combine to node
        return min(a, b);
    }
    void upd(int pos, T val) { // O(log(len))
        st[pos + len] = val;
        for (int p = (pos + len) / 2; p > 0; p /= 2) {
            st[p] = cb(st[2*p], st[2*p + 1]);
        }
    }
    T get(int l, int r) { // query in range[l, r) (include left border, exclude right border), using 0-indexed
        // O(log(len))
        T res_l = DEFAULT, res_r = DEFAULT;
        for (l += len, r += len; l < r; l /= 2, r /= 2) {
            if (l & 1) res_l = cb(res_l, st[l++]);
            if (r & 1) res_r = cb(st[--r], res_r);
        }
        return cb(res_l, res_r);
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
//        freopen("hi.out", "w", stdout);
    } 

    int n, l, r, x, type, q;    
    cin >> n >> q;
    Seg_Tree<int> st(n);
    while (cin >> type >> l >> r) {
        if (type == 1) {
            st.upd(l - 1, r);
        } else {
            cout << st.get(l - 1, r) << "\n";
        }
    }
}