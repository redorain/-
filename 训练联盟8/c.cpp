#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
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
int a[maxn], b[maxn], pos[maxn], ans[maxn], en, n;

// stack <int> ans;

int dfs(int s1, int s2, int l1, int r1, int l2, int r2) {
    // cout << s1 << ' ' << s2 << ' ' << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
    int ll = s1 - l1, rr = s1 + r1;
    int ll2 = s2 - l2, rr2 = s2 + r2;
    if (ll <= 0) ll += n;
    if (ll2 <= 0) ll2 += n;
    if (rr > n) rr = rr -= n;
    if (rr2 > n) rr2 -= n;
    if (rr == s1 || rr2 == s2 || ll == s1 || ll2 == s2) return 0;
    if (ll == rr && ll2 == rr2) {
        ans[n] = a[ll];
        return 1;
    }
    bool flag = 0;
    if (a[ll] == b[ll2]) {
        if (dfs(s1, s2, l1 + 1, r1, l2 + 1, r2) == 1)
            flag = 1,  ans[l1 + r1] = a[ll];
    }
    if (a[ll] == b[rr2] && flag == 0) {
        if (dfs(s1, s2, l1 + 1, r1, l2, r2 + 1) == 1)
            flag = 1, ans[l1 + r1] = a[ll];
    }
    if (a[rr] == b[ll2] && flag == 0) {
        if (dfs(s1, s2, l1, r1 + 1, l2 + 1, r2) == 1)
            flag = 1, ans[l1 + r1] = a[rr];
    }
    if (a[rr] == b[rr2] && flag == 0) {
        if (dfs(s1, s2, l1, r1 + 1, l2, r2 + 1) == 1)
            flag = 1, ans[l1 + r1] = a[rr];
    }
    return flag;
}


int main () {
    int T, m, k, x, y;
    sf("%d", &n);
    for2(i, 1, n) sf("%d", &a[i]);
    for2(i, 1, n) sf("%d", &b[i]), pos[b[i]] = i;
    bool flag = 0;
    for2(i, 1, n) {
        if (dfs(i, pos[a[i]], 1, 1, 1, 1) == 1) {
            x = i;
            ans[1] = i;
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        for2(i, 1, n) {
            if (i != n) printf("%d ", ans[i]);
            else printf("%d\n", ans[i]);
        }
    } else {
        printf("-1\n");
    }
    return 0;
}
