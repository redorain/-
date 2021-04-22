#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
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
double s[maxn]; int num[maxn];
double v[maxn];
double dp[maxn];

int main () {
    int T, n, m, k, x, y, V;
    sf("%d %d", &n, &V);
    for1(i, 0, n) sf("%lf", &s[i]);
    for1(i, 0, n) sf("%lf", &v[i]);
    for (int i = 0; i < n ; i++) {
        double price = v[i] / s[i];
        int cnt = 0;
        for (int j = 1; j <= s[i]; j *= 2) {
            num[cnt++] = j;
            s[i] -= j;
        }
        if (s[i]) num[cnt++] = s[i];
        for (int j = 0; j < cnt; j++) {
            for (int k = V; k >= num[j]; k--) {
                dp[k] = max(dp[k], dp[k - num[j]] + price * num[j]);
            }
        }
    }
    pf("%.2lf\n", dp[V]);
    return 0;
}
