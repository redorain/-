#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int MOD = 11;
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
    ll ans = 0ll;
    ll T, m, k, x, y;
    int n;
    while (sf("%d %lld", &n, &k) != EOF) {
        ll sum = 0ll;
        int now =  0;
        if (n == 2) {
            for1(i, 0, n)  {
                sf("%lld", &a[i]);
                if (a[i] != k)
                    sum = a[i];
                else {
                    if (now == 0) now = 1;
                    else sum = a[i];
                }
                // cout << sum << '\n';
            }
        } else {
            for1(i, 0, n)  {
                sf("%lld", &a[i]);
                if (a[i] != k)
                    sum = mod(a[i] + sum);
                else {
                    if (now == 0) now = 1;
                    else sum = mod(a[i] + sum);
                }
                // cout << sum << '\n';
            }
        }
        // cout << sum << '\n';
        pf("%lld\n", sum);
    }
    return 0;
}
