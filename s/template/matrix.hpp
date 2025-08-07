
#define arr vector<vector<int>>
arr operator*(arr& a, arr& b) {
    arr res(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int x = 0; x < b.size(); x++)
                res[i][j] = (res[i][j] + a[i][x] * b[x][j]) % MOD;
    return res;
}
map<int, arr> prev_res;
arr pow(int k) {
    if (prev_res.count(k)) {
        return prev_res[k];
    }
    int exp = k;
    auto a = K;
    arr res(a.size(), vector<int>(a.size()));
    for (int i = 0; i < a.size(); i++) res[i][i] = 1;
    for (; k > 0; k /= 2) {
        if (k & 1) res = res * a;
        a = a * a;
    }
    prev_res[exp] = res;
    return res;
}
arr operator+(arr a, arr& b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            a[i][j] = (a[i][j] + b[i][j]) % MOD;
        }
    }
    return a;
}