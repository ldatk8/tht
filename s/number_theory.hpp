array<int, 3> extended_euclid(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto x = extended_euclid(b, a % b);
    return {x[0], x[2], x[1] - a / b * x[2]};
}
int calc(int a, int b, int mod) {
    // https://open.kattis.com/submissions/13838133
    // (a / b) % mod
    auto g = extended_euclid(b, mod);
    if (g[0] != 1) return -1;
    int inv = (g[1] % mod + mod) % mod;
    return (a * inv) % mod;
}
const int MOD = 1e9 + 7;

ll pow(ll a, ll b, ll m) {
	ll res = 1;
	a %= m;  // to avoid overflows when a > 1e9
	while (b) {
		if (b & 1) { res = (res * a) % m; }
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

/** The extended Euclidean algorithm used to find the inverse */
void ext(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1, y = 0;
	} else {
		ext(b, a % b, x, y);
		ll tem = x;
		x = y;
		y = tem - (a / b) * y;
	}
}

/** @return the modular inverse of a mod m */
ll inv(ll a, ll m) {
	ll x = 0, y = 0;
	ext(a, m, x, y);
	return (x + m) % m;
}