#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
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
int a[maxn], pre[maxn];
int dp[maxn][maxn];

int main () {
    int T, n, m, h, l, r, k, x, y;
    sf("%d %d %d %d", &n, &h, &l, &r);
    for2(i, 1, n)  {
        sf("%d", &a[i]);
    }
    memset(dp, -INF, sizeof(dp));
    dp[0][0] = 0;
    int now = 0, num = 1, ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < h; j++) {
            dp[i][j] = max(dp[i - 1][(j - a[i] + h) % h], dp[i - 1][(j - a[i] + 1 + h) % h]);
            if(l <= j && j <= r) dp[i][j]++;
            ans = max(dp[i][j], ans);
        }
    }
    pf("%d\n", ans);
    return 0;
}
