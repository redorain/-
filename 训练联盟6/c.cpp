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
int a[10], b[maxn];
string sr[10], sc[10], s[10];
int rcnt[10], ccnt[10];
int row[10], col[10];
int vis[10][10];
P pos[10][10], pos2[10][10], shot[10];



int main () {
    IO;
    ll ans = 0ll;
    int T, n, m, k, x, y;
    cin >> n >> k;
    for1(i, 0, k) cin >> a[i];
    for1(i, 0, n) cin >> s[i];5885
    int cnt = 0;
    if(k == 1) {
        
    }
    else if(k == 2) {
        
    }
    else if(k == 3) {

    }
    else if(k == 4) {

    }
    else {

    }
    return 0;
}
