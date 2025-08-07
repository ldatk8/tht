/**
 *    author : Lăng Trọng Đạt
 *    created: 22-10-2024
**/
#include <bits/stdc++.h>
using namespace std;
#ifndef LANG_DAT
#define db(...) ;
#endif // LANG_DAT
#define int long long
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a); (i) <= (b); (i++))
#define si(x) (int)(x.size())
void inline mx(int& a, int b) { if (b > a) a = b; }
void inline mi(int& a, int b) { if (b < a) a = b; }
using pii = pair<int, int>;
 
const int INF = 1e18 + 5;
const int MOD = 1e9 + 7;
 
struct Point {
    int x, y;
    Point(int a, int b) {
        x = a;
        y = b;
    }
    Point() {

    }
    friend ostream& operator<<(ostream& out, Point& p) {
        out << "[" << p.x << " " << p.y << "]";
        return out;
    }
    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }
};
 
const int N = 1e6 + 5;
int g[N];
int n, m, k, q;
 
 
/*  
    phi := angle between vecto (ap) and vecto(ab) (-180 < phi < 180)
    if (phi > 0) p is in right of line
    using cross product to determine angle is positive or negetive (right hand rule)
    https://cses.fi/problemset/task/2189
*/
int location(Point& a, Point& b, Point& p) {
    int hi = (p.x - a.x) * (b.y - a.y) - (b.x - a.x) * (p.y - a.y);
 
    if (hi == 0) return 0; // p touch the line
    else if (hi > 0) return 1; // p in righ of line
    else return -1; // p in left of line
}
 
bool line_segment_intersection(Point& a, Point& b, Point& c, Point& d) {
    // https://cses.fi/problemset/result/10950189/
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    x1 = min(a.x, b.x); x2 = max(a.x, b.x);
    y1 = min(a.y, b.y); y2 = max(a.y, b.y);
    x3 = min(c.x, d.x); x4 = max(c.x, d.x);
    y3 = min(c.y, d.y); y4 = max(c.y, d.y);
 
    return (location(a, b, c) * location(a, b, d) <= 0 &&
            location(c, d, a) * location(c, d, b) <= 0 && 
            !(x2 < x3 or x4 < x1 or y2 < y3 or y4 < y1));
}

int polygon_area(vector<Point>& p) {
    // using shoelace formular (https://www.youtube.com/watch?v=0KjG8Pg6LGk&ab_channel=Mathologer)
    // https://cses.fi/problemset/result/10950565/
    int ans = 0;
    FOR(i, 0, si(p) - 1) {
        ans += p[i].x * p[(i + 1) % si(p)].y - p[i].y * p[(i + 1) % si(p)].x;
    }
    return abs(ans);
}

bool quick_check(Point& a, Point& b, Point& p) {
    return !(p.x < min(a.x, b.x) or max(a.x, b.x) < p.x or
             p.y < min(a.y, b.y) or max(a.y, b.y) < p.y);
}
/*
    * make a ray goes through point p (ray casting)
    * if it cut poly in one point, then it is inside
    * https://usaco.guide/plat/geo-pri?lang=cpp#explanation-3
    * https://cses.fi/problemset/result/10950861/
*/
int pos_point_to_polygon(vector<Point>& poly, Point& p) {
    Point another(1e9 + 32, 1e9 + 49);
    int cnt = 0;
    FOR(i, 0, si(poly) - 1) {
        if (quick_check(poly[i], poly[(i + 1) % si(poly)], p) &&
            location(poly[i], poly[(i + 1) % si(poly)], p) == 0) return 0; // BOUNDARY
        cnt += line_segment_intersection(poly[i], poly[(i + 1) % si(poly)], p, another);
    }
    if (cnt & 1) return 1; // "INSIDE";
    else return -1; // out
}

/*
    * Using schoelace formula to calculate area and vector to cnt vertices
    then use pick's theorem to determine #point inside
    * 2*area = 2*i + b - 2
    * https://www.youtube.com/watch?v=bYW1zOMCQno&ab_channel=PBSInfiniteSeries
    * Verification https://cses.fi/problemset/result/10961047/
    * Sources: https://usaco.guide/plat/geo-pri?lang=cpp#lattice-points-in-polygon
    * TC: O(n)
*/
pii polygon_lattice_points(vector<Point>& poly) {
    // return the number of lattice points {inside, boundary}
    int area = 0, boundary = 0;
    FOR(i, 0, si(poly) - 1) {
        Point &a = poly[i], &b = poly[(i + 1) % si(poly)];
        area += a.x * b.y - a.y * b.x;
        boundary += __gcd(abs(a.x - b.x), abs(a.y - b.y));
    }
    pii res = {(abs(area) - boundary + 2) / 2, boundary};
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("hi.inp", "r")) {
        freopen("hi.inp", "r", stdin);
    //    freopen("hi.out", "w", stdout);
    } 
 
    cin >> n;
    vector<Point> poly(n);
    for (Point& x : poly) cin >> x;

    pii res = polygon_lattice_points(poly);
    cout << res.first << " " << res.second;
}