int rmq[MAXN][22];
void pre_process() {
    int len = n;
	FOR(i, 1, len) rmq[i][0] = g[i];
	FOR(i, 1, 21) {
		FOR(j, 1, len - (1 << i) + 1) {
			rmq[j][i] = min(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
		}
	}
}
int get_min(int lx, int rx) {
	int lm = 31 - __builtin_clz(rx - lx + 1);
	return min(rmq[lx][lm], rmq[rx - (1 << lm) + 1][lm]);
}