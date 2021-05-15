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

struct node {
    int par, ls, rs, val;
} a[1005], b[1005];

void givepa(int x) {
    int y = x - 1, last = x;
    while (y >= 0) {
        if (a[y].val <= a[x].val) {
            last = y;
            y = a[y].par;
        } else break;
        if (y == 0) break;
    }
    if (last == x) {
        a[last].ls = x;
        a[x].par = last;
    } else {
        bool ok = 0;
        while (ok == 0) {
            cout << "f";
            if (a[last].rs == -1 && a[x].val >= a[last].val) {
                a[x].par = last;
                a[last].rs = x;
                ok = 1;
            }
            if (a[last].ls == -1 && ok == 0 && a[x].val < a[last].val) {
                a[x].par = last;
                a[last].ls = x;
                ok = 1;
            }
            if (a[x].val >= a[last].val && ok == 0) last = a[last].rs;
            if (a[x].val < a[last].val && ok == 0) last = a[last].ls;
        }
    }
}


void givepa2(int x) {
    int y = x - 1, last = x;
    while (y >= 0) {
        if (b[y].val <= b[x].val) {

            last = y;
            y = b[y].par;
        } else break;
        if (y == 0) break;
    }
    if (last == x) {
        b[last].rs = x;
        b[x].par = last;
    } else {
        bool ok = 0;
        while (ok == 0) {
            if (b[last].rs == -1 && b[x].val < b[last].val) {
                b[x].par = last;
                b[last].rs = x;
                ok = 1;
            }
            if (b[last].ls == -1 && ok == 0 && b[x].val >= b[last].val) {
                b[x].par = last;
                b[last].ls = x;
                ok = 1;
            }
            if (b[x].val >= b[last].val && ok == 0) last = b[last].ls;
            if (b[x].val < b[last].val && ok == 0) last = b[last].rs;
        }
    }
}

int check1(int x, int ch) {
    node now = a[x];
    int mx = now.val, mn = now.val;
    if (now.ls != -1) {
        mx = check1(now.ls, 1);
        if (mx == 0 || mx >= now.val) return 0;
    }
    if (now.rs != -1) {
        mn = check1(now.rs, 2);
        if (mn < now.val || mn == 0) return 0;
    }
    if (ch == 1) return max(max(mx, now.val), mn);
    else return min(min(mx, now.val), mn);
}

int check2(int x, int ch) {
    node now = b[x];
    int mx = now.val, mn = now.val;
    if (now.ls != -1) {
        mn = check2(now.ls, 1);
        if (mn == 0 || mn < now.val) return 0;
    }
    if (now.rs != -1) {
        mx = check2(now.rs, 2);
        if (mx >= now.val || mx == 0) return 0;
    }
    if (ch == 1) return min(min(mx, now.val), mn);
    else return max(max(mx, now.val), mn);
}

void out (int x, node y[]) {
    node now = y[x];
    if (now.ls != -1) {
        out(now.ls, y);
    } else {
        printf("%d ", now.val);
    }
    if (now.rs != -1) {
        out(now.rs, y);
    } else {
        printf("%d ", now.val);
    }
    if (now.ls && now.rs) printf("%d ", now.val);
}

int main () {
    ll ans = 0ll;
    int T, n, m, k, x, y;
    sf("%d", &n);
    for1(i, 0, n)  sf("%d", &a[i].val), b[i].val = a[i].val, b[i].ls = -1, b[i].rs = -1, a[i].ls = -1, a[i].rs = -1;
    a[0].par = -1, b[0].par = -1;
    for1(i, 1, n) {
        givepa(i);
        givepa2(i);
    }
    cout << 234 << '\n';
    bool flag1 = 1, flag2 = 1;
    if (check1(0, 1) && check1(0, 2)) {
        out(0, a);
        return 0;
    }
    if (check2(0, 1) && check2(0, 2)) {
        out(0, b);
        return 0;
    }
    puts("NO");
    return 0;
}
