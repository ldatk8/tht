struct DSU {
    vi far, sz;
    vector<pair<int &, int>> history;
    DSU(int n) {
        far.resize(n + 1);
        sz = vi(n + 1, 1);
    }
    int get(int x) { return far[x] == 0? x : get(far[x]); }
    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (sz[a] < sz[b]) swap(a, b);
        history.pb({sz[a], sz[a]});
        history.pb({far[b], far[b]});
        if (a != b) {
            far[b] = a;
            sz[a] += sz[b];
        }
    }
    void rollback() {
        // rollback size
        history.back().f = history.back().se;
        history.pop_back();
        // rollback parent
        history.back().f = history.back().se;
        history.pop_back();
    }
    void rollback(int until) {
        while (history.size() > until) {
            rollback();
        }
    }
    int get_sz(int v) {
        return sz[get(v)];
    }
} dsu(0);

// https://dmoj.ca/submission/6438697