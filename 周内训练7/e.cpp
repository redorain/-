#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
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
string a, b;
ll pre[maxn];

ll ksm(ll expon_a, ll expon_n) {
    ll Base = expon_a, Ans = 1ll;
    while (expon_n > 0) {
        if (expon_n & 1ll)
            Ans = mod(Ans * Base);
        Base = mod(Base * Base);
        expon_n >>= 1;
    }
    return Ans;
}

int main () {
    IO;
    ll ans = 0ll;
    int T, n, m, k, x, y;
    cin >> n >> m;
    cin >> a >> b;
    if (n > m) {
        for (int i = 0; i < (n - m); i++) {
            b = '0' + b;
        }
        m = n;
    }
    if (n < m) {
        for (int i = 0; i < (m - n); i++) {
            a = '0' + a;
        }
        n = m;
    }
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            if (b[i] == '1')
                pre[i] = 1ll;
            else
                pre[i] = 0ll;
            continue;
        }
        if (b[i] == '1') {
            if (i == 0) {
                pre[i] = 1;
            } else
                pre[i] = pre[i - 1] + 1;
        } else
            pre[i] = pre[i - 1];
    }
    ll base = 1ll;
    // cout << a << '\n';
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == '1') {
            ans = mod(mod(base * pre[i]) + ans);
            // cout << base *pre[i] << '\n';
        }
        base = base * 2ll % MOD;
    }
    cout << ans << '\n';
    return 0;
}
