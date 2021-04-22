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
ll a[maxn], b[maxn];
int vis[35];

int main () {
    ll ans = 0ll;
    int T, n, m, k, x, y;
    sf("%d", &T);
    while (T--) {
        memset(vis, 0, sizeof(vis));
        sf("%d", &n);
        int cnt = 0;
        bool flag = 1;
        for1(i, 0, n)  {
            sf("%lld", &a[i]);
            if (a[i] != 0) b[cnt++] = a[i];
        }
        for (int i = 0; i < cnt; i++) {
            int l = 1;
            if (i > 0 && b[i] != b[i - 1]) flag = 0;
            ll temp = b[i];
            while (temp) {
                if (temp & 1) vis[l]++;
                l++;
                temp >>= 1;
            }
        }
        // cout << flag << '\n';
        if (flag == 1) {
            pu;
            continue;
        }
        flag = 1;
        for (int i = 1; i < 35; i++) {
            if (vis[i] % 2 != 0) flag = 0;
            // cout << vis[i] << '\n';
        }
        pu;
    }
    return 0;
}
