#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int EPS = 1e-8;
#define ll long long
#define for1(i, a, b) for (int i = (a); i < (b); i++)
#define for2(i, a, b) for (int i = (a); i <= (b); i++)
#define for3(i, a, b) for (int i = (a); i >= (b); i--)
#define fore(i, u)    for(int i = h[u]; i; i = e[i].next)
#define IO ios::sync_with_stdio(false)
#define sf scanf
#define pf printf
#define db double
#define pu puts(flag? "YES": "NO")
#define lowbit(x) ((x) & (-(x)))
#define mid ((l + r) >> 1)
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define P pair<int, int>
#define mod(x) ((x) % MOD)
int a[maxn], b[maxn];

int dcmp(db x){
    if (fabs(x) < EPS) return 0;   
    return x > 0 ? 1 : -1;
}


int main () {
    ll ans = 0ll;
    int T, n, m, k, x, y;
    sf("%d", &T);
    while(T--) {
        sf("%d", &n);
        for1(i, 0, n)  sf("%d", &a[i]);
        
        pf("%lld\n", ans);
    }
    return 0;
}
