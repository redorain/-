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
int h[maxn], s[maxn];
ll w[maxn], dp[500][500];

int main () {
    ll ans = 0ll;
    int T, n, m, x, y, H, S;
    sf("%d", &n);
    sf("%d", &H);
    sf("%d", &S);
    for1(i, 0, n)  {
        sf("%d %d %lld", &h[i], &s[i], &w[i]);
        for(int j = H; j > h[i]; j--) {
            for(int k = S; k >= 0; k--) {
                if(k >= s[i])
                dp[j][k] = max(dp[j][k], dp[j - h[i]][k - s[i]] + w[i]);
                else if(j - s[i] - h[i] + k > 0)
                dp[j][k] = max(dp[j][k], dp[j - s[i] - h[i] + k][0] + w[i]);
                ans = max(ans, dp[j][k]);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
