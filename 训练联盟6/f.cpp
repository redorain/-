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

vector <P> a[5555];
vector <int> val[2555];

int cal(P x, P y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int main () {
    // ll ans = 0ll;
    int T, n, m, k, x, y;
    sf("%d %d", &n, &k);
    for1(i, 0, n) {
        for1(j, 0, n) {
            sf("%d", &x);
            a[x].push_back({i, j});
            if(x != 1)
                val[x].push_back(INF);
            else val[x].push_back(0);
        }
    }
    bool flag = 1;

    for2(i, 1, k - 1) {
        if (a[i].size() == 0 || a[i + 1].size() == 0) {
            flag = 0;
            break;
        }
        for1(j, 0, a[i].size()) {
            for1(k, 0, a[i + 1].size()) {
                val[i + 1][k] = min(val[i + 1][k], val[i][j] + cal(a[i][j], a[i + 1][k]));
                // cout << val[i + 1][k] << '\n';
            }
        }
    }
    if (flag == 1) {
        int ans = INF;
        for (int i = 0; i < a[k].size(); i++) {
            ans = min(ans, val[k][i]);
        }
        printf("%d\n", ans);
    } else printf("-1\n");

    return 0;
}
