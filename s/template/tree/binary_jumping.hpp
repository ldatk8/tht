 
const int MAXN = 2e5 + 5;
const int EXP = 20;
int up[EXP][MAXN], d[MAXN];
 
vector<int> adj[MAXN];
int n, q;
 
void dfs(int v, int prev = -1, int depth = 0) {
    d[v] = depth;
    for (int u : adj[v]) {
        if (u != prev) {
            dfs(u, v, depth + 1);
            up[0][u] = v;
        }
    }
}
void build() {
    memset(up, -1, sizeof(up));
    dfs(1);
    up[0][1] = -1;
    for (int i = 1; i < EXP; i++) {
        for (int v = 1; v <= n; v++) {
            if (up[i - 1][v] != -1)
                up[i][v] = up[i - 1][up[i - 1][v]];
        }
    }
}
int jump(int v, int k) {
    for (int i = 0; i < EXP; i++) {
        if ((1 << i) & k)
            v = up[i][v];
    }
    return v;
}
int lca(int a, int b) {
    a = jump(a, d[a] - min(d[a], d[b]));
    b = jump(b, d[b] - min(d[a], d[b]));
    for (int i = EXP - 1; i >= 0; i--) {
        if (up[i][a] != up[i][b])
            a = up[i][a], b = up[i][b];
    }
    return (a == b ? a : up[0][a]);
}
int dist(int a, int b) {
    return d[a] + d[b] - 2*d[lca(a, b)];
}