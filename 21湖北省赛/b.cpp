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
struct node {
    int p;
    double v;
    bool operator < (const node y) const {
        return v < y.v;
    }
} a[maxn];

priority_queue <node> q1, q2;

int main () {
    int T, n, m, k, t,  y;
    double x;
    sf("%d %d %d %d", &n, &m, &t, &k);
    for2(i, 1, n)  {
        node temp;
        sf("%lf", &x);
        temp.v = x, temp.p = i;
        q2.push(temp);
        a[i] = temp;
    }
    for2(i, 1, m)  {
        node temp, t;
        sf("%lf", &x);
        temp.v = x, temp.p = i + n;
        temp.v = x * 0.8;
        q2.push(temp);
        a[temp.p] = temp;
    }
    double ans = 0.0;
    for1(i, 0, t) {
        node now = q2.top();
        q2.pop();
        ans += now.v;
        now.v *= 0.6;
        a[now.p].v = now.v;
        q2.push(now);
    }
    for2(i, 1, n) {

    }
    for1(i, 0, t - k) {
        double now = q2.top();
        q2.pop();
        q2.push(now * 0.6);
    }
    return 0;
}
