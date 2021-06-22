#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
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
int vis[maxn], vis2[maxn];

struct Point {
    ll x, y;
    Point (ll x, ll y): x(x), y(y) {}
    Point () {}
    bool operator < (Point p) {
        if (max(x, y) == max(p.x, p.y)) {
            if (x == p.x) return y > p.y;
            return x < p.x;
        }
        return max(x, y) < max(p.x, p.y);
    }
} p[maxn], pre[maxn], suf[maxn];

int main () {
    ll T, n, m, k, x, y, xx, yy;
    sf("%lld", &n);
    for1(i, 0, n) {
        sf("%lld %lld", &xx, &yy);
        p[i].x = xx, p[i].y = yy;
    }
    sort(p, p + n);
    cout << '\n';
    ll ans = 0ll;
    Point now = Point(0, 0);
    ll level = 0ll;
    int cnt = 0;
    vis2[0] = 0;
    for1(i, 0, n) {
        if (max(p[i].x, p[i].y) == level) {
            ans += abs(p[i].x - now.x) + abs(p[i].y - now.y);
            now = p[i];
            level = max(p[i].x, p[i].y);
        } else {
            cnt++;
            pre[cnt] = p[i];
            suf[cnt - 1] = now;
            if (now.x == now.y) {
                vis[cnt - 1] = 3;
            } else if (now.x < now.y) {
                vis[cnt - 1] = 1;
            } else {
                vis[cnt - 1] = 2;
            }
            if (p[i].x == p[i].y) {
                vis2[cnt] = 3;
            } else if (p[i].x < p[i].y) {
                vis2[cnt] = 1;
            } else {
                vis2[cnt] = 2;
            }
            now = p[i];
            level = max(p[i].x, p[i].y);
        }
    }
    suf[cnt] = now;
    cout << ans << '\n';
    for (int i = 0; i < cnt; i++) {
        // if (vis[i] == 1) {
        //     ans += abs(pre[i + 1].x - pre[i].x) + abs(pre[i + 1].y - pre[i].y);
        // } else if (vis[i] == 2) {
        //     ans += abs(suf[i + 1].x - suf[i].x) + abs(suf[i + 1].y - suf[i].y);
        // } else {
        ans += min(abs(pre[i + 1].x - pre[i].x) + abs(pre[i + 1].y - pre[i].y),
                   min(abs(suf[i + 1].x - suf[i].x) + abs(suf[i + 1].y - suf[i].y), 
                   min(abs(pre[i + 1].x - suf[i].x) + abs(pre[i + 1].y - suf[i].y), 
                   abs(suf[i + 1].x - pre[i].x) + abs(suf[i + 1].y - pre[i].y))));
        // }
    }
    pf("%lld\n", ans);
    return 0;
}
