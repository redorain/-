#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
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
int a[maxn], vis[maxn];

struct node {
    int pos, val, nxt;
}c[maxn];

vector <node> v1, v2;

void out(vector <node> x) {
    int l = x.size();
    for(int i = 0; i < l; i++) {
        printf("%05d %d ", x[i].pos, x[i].val);
        if(i != l - 1) {
            printf("%05d\n", x[i + 1].pos);
        }
        else printf("-1\n");
    }
}

int main () {
    ll ans = 0ll;
    int a1, n;
    sf("%d %d", &a1, &n);
    for(int i = 0; i < n; i++) {
        int pp, vv, nn;
        sf("%d %d %d", &pp, &vv, &nn);
        a[pp] = nn;
        c[pp].pos = pp, c[pp].val = vv, c[pp].nxt = nn;
    }
    int temp = a1;
    while(temp != -1) {
        node now = c[temp];
        if(!vis[abs(now.val)]) {
            vis[abs(now.val)] = 1;
            v1.push_back(now);
        }
        else {
            v2.push_back(now);
        }
        temp = a[temp];
    }
    out(v1);
    out(v2);
    return 0;
}
