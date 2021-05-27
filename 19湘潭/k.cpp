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
int vis[maxn];

struct node {
    int val, su;
    bool operator < (node y) {
        if (su == y.su) {
            return val < y.val;
        }
        return su < y.su;
    }
} a[maxn];

bool check1() {
    bool flag = 0;
    if (vis[11] >= 1 && vis[19] >= 1 && vis[21] >= 1 && vis[29] >= 1 && vis[31] >= 1 && vis[39] >= 1 && vis[41] >= 1 && vis[42] >= 1 && vis[43] >= 1 && vis[44] >= 1 &&
            vis[45] >= 1 && vis[46] >= 1 && vis[47] >= 1) flag = 1;
    return flag;
}

bool check2() {
        bool flag = 0;
    for(int i = 1; i <= 3; i++) {
        int ct = i * 10;
        if(vis[ct + 1] >= 3 && vis[ct + 2] >= 1 && vis[ct + 3] >= 1 && vis[ct + 4] >= 1 && vis[ct + 5] >= 1
        && vis[ct + 6] >= 1 && vis[ct + 7] >= 1 && vis[ct + 8] >= 1 && vis[ct + 9] >= 3) flag = 1;
    }
    return flag;
}

int main () {
    IO;
    ll ans = 0ll;
    int T, n, m, k, x, y;
    T = 14;
    for (int i = 0; i < 14; i++) {
        string now;
        cin >> now;
        node no;
        if (now == "dong")   no.val = 1, no.su = 4;
        else if (now == "nan")    no.val = 2, no.su = 4;
        else if (now == "xi")   no.val = 3, no.su = 4;
        else if (now == "bei")  no.val = 4, no.su = 4;
        else if (now == "zhong") no.val = 5, no.su = 4;
        else if (now == "fa")   no.val = 6, no.su = 4;
        else if (now == "bai") no.val = 7, no.su = 4;
        else {
            no.val = now[0] - '0';
            if (now[1] == 'w') no.su = 1;
            else if (now[1] == 's') no.su = 2;
            else no.su = 3;
        }
        a[i] = no;
    }
    sort(a, a + 14);
    for (int i = 0; i < 14; i++) {
        vis[a[i].val + a[i].su * 10]++;
    }
    if (check1() == 1) {
        cout << "shisanyao!" << '\n';
    } else if (check2() == 1) {
        cout << "jiulianbaodeng!" << '\n';
    } else {
        cout << "I dont know!" << '\n';
    }
    return 0;
}
