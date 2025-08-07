#include <bits/stdc++.h>
using namespace std;
#ifndef LANG_DAT
#define db(...) ;
#endif // LANG_DAT
#ifndef LANG_DAT
#define db(...) ;
#endif // LANG_DAT
#define int long long
#define f first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); (i) <= (b); (i++))
#define FD(i, a, b) for (int i = (b); (i) >= (a); (i--))
#define si(x) (int)(x.size())
bool mx(int& a, int b) { if (b > a) {a = b; return true;} return false;}
bool mi(int& a, int b) { if (b < a) {a = b; return true;} return false;}
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e6 + 5;
int g[N];
int n, m, k, a, b;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(1, 1000); // use int a = dist(rng)
void gen() {
    ofstream out;
    out.open("hi.inp");
    n = 5;

    out.close();
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    srand(time(NULL));

    int tc = 2000;

    system(string("g++ ans.cpp -o ans.exe").c_str());
    system(string("g++ a.cpp -o trau.exe").c_str());

    FOR(i, 1, tc) {
        gen();
        system(string("ans.exe").c_str());
        system(string("trau.exe").c_str());

        if (system(string("fc hi.out ans.out").c_str())) {
            db("fuckkkkkkkkkkk\n\nfuckkkkk");
            exit(0);
        }
    }
}
