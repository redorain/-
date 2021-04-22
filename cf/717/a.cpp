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
int a[maxn], b[maxn];

int main () {
    ll ans = 0ll;
    int T, n, m, k, x, y;
    sf("%d", &T);
    while(T--) {
        sf("%d %d", &n, &k);
        for1(i, 0, n)  sf("%d", &a[i]);
        int now = 0;
        int cnt = 0;
        while(now < n - 1) {
            while(a[now] == 0) now++;
            int i = now, j = n - 1;
            while(cnt < k) {
            while(a[i] == 0) i++;
            j = n - 1;
            if(i >= j) break;
            a[i]--, a[j]++;
            cnt++;
            }
            now++;
        }
        for1(x, 0, n) {
            pf("%d", a[x]);
            if(x != n - 1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
