#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int MOD = 998244353;
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
int a[maxn], b[maxn];

ll ksm(ll expon_a, ll expon_n) {
    ll Base = expon_a, Ans = 1;
    while (expon_n > 0) {
        ;
        if (expon_n & 1)
            Ans = mod(Ans * Base);
        Base = mod(Base * Base);
        expon_n >>= 1;
    }
    return Ans;
}


int main () {
    ll T, n, m, k, x, y;
    sf("%lld", &T);
    while (T--) {
        sf("%lld", &n);
        if (n % 2 == 1) {
            pf("0\n");
            continue;
        }
        pf("%lld\n", ksm(2, n / 2));
    }
    return 0;
}
