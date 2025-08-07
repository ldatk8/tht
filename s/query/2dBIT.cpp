
template<int... Arg> struct BIT {
    int val = 0;
    void upd(int v) { val += v; }
    int query() { return val; }
    int sum() { return val; }
};
template<int N, int... Ns> struct BIT<N, Ns...> {
    BIT<Ns...> bit[N + 1];
    template<typename... Args> void upd(int pos, Args... args) {
        for (; pos <= N; pos += pos & (-pos)) bit[pos].upd(args...);
    }
    template<typename... Args> int sum(int pos, Args... args) {
        int ans = 0;
        for (; pos > 0; pos -= pos & (-pos)) ans += bit[pos].sum(args...);
        return ans;
    }
    // i don't why it work
    template<typename... Args> int query(int l, int r, Args... args) {
        int ans = 0;
        for (; r > 0; r -= r & (-r)) ans += bit[r].query(args...);
        for (--l; l > 0; l -= l & (-l)) ans -= bit[l].query(args...);
        return ans;
    }
};
