#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
#define eps 1e-9
#define ll long long
#define for1(i, a, b) for (int i = (a); i < (b); i++)
#define for2(i, a, b) for (int i = (a); i <= (b); i++)
#define for3(i, a, b) for (int i = (a); i >= (b); i--)
#define fore(i, u)    for(int i = h[u]; i; i = e[i].next)
#define IO ios::sync_with_stdio(false)
#define sf scanf
#define pf printf
#define pu puts(flag? "YES": "NO")
#define lowbit(x) ((x) & (-(x)))
#define mid ((l + r) >> 1)
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define P pair<int, int>
#define mod(x) ((x) % MOD)
int a[maxn], b[maxn];

double dcmp(double x) {
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

struct Point{
    double x, y;
    Point (){}
    Point (double x, double y): x(x), y(y) {}
    Point operator - (Point yy) {
        return Point(x - yy.x, y - yy.y);
    }
    double operator ^ (Point yy) {
        return (x * yy.y - y * yy.x);
    }
}p[maxn];

int main () {
    double ans = 0.0;
    int T, n, m, k, x, y;
        sf("%d", &n);
        for1(i, 0, n)  {
            double xx, yy;
            sf("%lf %lf", &xx, &yy);
            p[i] = Point(xx, yy);
            if(i > 1) {
                ans += fabs((p[i] - p[0]) ^ (p[i - 1] - p[0])) * 0.5;
            }
        }
        x = round(ans);
        pf("%d\n", x);
    return 0;
}
