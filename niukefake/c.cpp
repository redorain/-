#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int MOD = 1000;
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
    while(expon_n > 0) {;
        if(expon_n & 1)
            Ans = mod(Ans * Base);
        Base = mod(Base * Base);
        expon_n >>= 1;
    }
    return Ans;
}

string s, an;

int main () {
    ll ans = 0ll;
    ll    T, n, m, k, x, y;
    while(sf("%lld", &n) != EOF) {
        
        // for1(i, 0, n)  sf("%d", &a[i]);
        ans = ksm(5ll, n);
        s = to_string(ans);
        int len = s.size();
        char ch[4];
        int cnt =  2;
        an.clear();
        for3(i, len - 1, len - 3) {
            an = s[i] + an;
            if(i == 0) break;
        }
        int l = an.size();
        // cout << l << '\n';
        for(l; l < 3; l++) {
            an = '0' + an;
        }
            cout << an << '\n';
    }
    return 0;
}
