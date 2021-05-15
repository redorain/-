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
    int hh, mm;
    sf("%02d:%02d", &hh, &mm);
    cout << hh << ' ' << mm << '\n';
    x = hh, y = mm;
    if(mm > 0) hh++;
    hh -= 12;
    if(hh <= 0) {
        printf("Only %02d:%02d.  Too early to Dang.\n", x, y);
    }
    else {
        while(hh--) {
            printf("Dang");
        }
        printf("\n");
    }
    return 0;
}
