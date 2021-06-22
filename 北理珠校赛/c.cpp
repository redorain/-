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
ll a[maxn], b[maxn];

int main () {
    ll T, n, m, w, c, k, x, y;
    cin >> n >> w >> c;
    for1(i, 0, n)  cin >> a[i];
    sort(a, a + n);
    ll now = 0ll, ans = 0ll;
    int i = 0;
    for(; i < n; i++) {
        if (w - a[i] > 0 && now + a[i] <= c)
            ans += w - a[i], now += a[i];
    }
    cout << ans << '\n';
    return 0;
}
