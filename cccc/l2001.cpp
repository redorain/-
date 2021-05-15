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
int val[maxn], h[maxn], dis[maxn], num[maxn], peo[maxn];
int cnt;

struct tst {
    int x, y, z;
    bool operator < (const tst ww) const {
        if (x == ww.x) return z < ww.z;
        else return x > ww.x;
    }
};

map <tst, int> mp;
priority_queue <tst> q;

struct node {
    int next, w, to;
} e[maxn];
vector <int> road[maxn]

void add(int u, int v, int w) {
    e[++cnt].next = h[u];
    e[cnt].to = v;
    e[cnt].w = w;
    h[u] = cnt;
}

void dij(int S, int D) {
    dis[S] = 0;
    q.push({0, S, val[S]});
    mp[ {0, S, val[S]}] = 1;
    while (!q.empty()) {
        tst now = q.top();
        q.pop();
        for (int i = h[now.y]; i; i = e[i].next) {
            node no = e[i]; tst temp;
            temp.x = now.x + no.w, temp.z = now.z + val[no.to], temp.y = no.to;
            if (dis[no.to] > temp.x) {
                road[no.to] = road[now.y];
                road[no.to].push_back(no.to);
                dis[no.to] = temp.x;
                peo[no.to] = temp.z;
                num[no.to] = num[now.y];
                if(no.to != D) q.push(temp);
            } else if (dis[no.to] == temp.x) {
                if (temp.z > peo[no.to]) {
                    num[no.to] = num[now.y];
                    peo[no.to] = temp.z;
                    road[no.to] = road[now.y];
                    road[no.to].push_back(no.to);
                    if(no.to != D) q.push(temp); 
                }
                num[no.to]++;
            }
        }
    }
}

int main () {
    cnt = 0;
    int S, D, n, m;
    sf("%d %d %d %d", &n, &m, &S, &D);
    for (int i = 0; i < n; i++) {
        sf("%d", &val[i]);
        dis[i] = INF;
        peo[i] = 0;
        num[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int uu, vv, ww;
        sf("%d %d %d", &uu, &vv, &ww);
        add(uu, vv, ww);
        add(vv, uu, ww);
    }
    if(S == D) {
        printf("1 %d\n%d %d\n", val[S], S, S);
        return 0;
    }
    dij(S, D);
    printf("%d %d\n", num[D], peo[D]);
    printf("%d ", S);
    int len = road[D].size();
    for(int i = 0; i < len; i++) {
        if(i != len - 1) printf("%d ", road[D][i]);
        else printf("%d\n", road[D][i]);
    }
    return 0;
}
