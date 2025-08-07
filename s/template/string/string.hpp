#include <bits/stdc++.h>
using namespace std;

int LCA(string& t, string& s) {
    // https://leetcode.com/problems/longest-common-subsequence/
    int n = t.size(), m = s.size();
    vector<vector<int>> dp(2, vector<int>(m + 1));
    for (int i = 1; i <= t.size(); i++) {
        bool id = i & 1;
        for (int j = 1; j <= s.size(); j++) {
            dp[id][j] = max(dp[!id][j], dp[id][j - 1]);
            if (s[j - 1] == t[i - 1])
                dp[id][j] = max(dp[id][j], dp[!id][j - 1] + 1);
        }
    }
    return dp[n & 1][m];
}
struct Hash {
	vi p_pow = {1};
	vi hash;
	int M;
	void init(string& s, int m = 1e9 + 7, int B = 107) {
		M = m;
		p_pow.resize(si(s) + 1);
		hash.resize(si(s) + 1);
		FOR(i, 1, si(s)) {
			p_pow[i] = (p_pow[i - 1] * B) % M;
			hash[i] = (hash[i - 1] * B + s[i - 1]) % M;
		}
	}
	int get(int l, int r) { // 1 index
		return ((hash[r] - hash[l - 1] * p_pow[r - l + 1]) % M + M) % M;
	}
};
