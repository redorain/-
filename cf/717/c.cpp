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
int a[maxn], b[maxn], vis[maxn];
int cnt, prime[maxn];
int pre[maxn], pre2[maxn];

vector <int> v[1300], v2[1300];

void find_prime() {
    cnt = 0;
    for (int i = 2; i <= 10005; i++) {
        if (vis[i] == 0) prime[cnt++] = i;
        for (int j = 0; i * prime[j] <= 10005 && j < cnt ; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}


int main () {
    find_prime();
    int T, n, m, k, q, y;
    sf("%d %d", &n, &q);
    int mx = 0;
    for2(i, 1, n)  sf("%d", &a[i]), mx = max(mx, a[i]);
    for (int i = 0; i < cnt; i++) {
        v[i].push_back(0);
        int x = prime[i];
        if (x > mx) break;
        int num = 1;
        for (int j = 1; j <= n; j++) {
            if (a[j] % x == 0) v2[i].push_back(j), num++;
            v[i].push_back(num);
        }
    }
    // for (int i = 0; i < cnt; i++) {
    //     int x = prime[i];
    //     if (x > mx) break;
    //     for (int j = 1; j < v[i].size(); j++) cout << v[i][j] << " ";
    //     cout << '\n';
    //     for (int j = 0; j < v2[i].size(); j++) cout << v2[i][j] << ' ';
    //     cout << '\n';
    // }
    while (q--) {
        int l, r;
        int ans = 0;
        sf("%d %d", &l, &r);
        for (int i = 0; i < cnt; i++) {
            int x = prime[i];
            if (x > mx) break;
            if (v2[i].size() >= 2 && l == v2[i][v[i][l] - 2]) ans = max(ans, v[i][r] - v[i][l] + 1);
            else ans = max(ans, v[i][r] - v[i][l]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
