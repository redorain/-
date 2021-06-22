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
int a[maxn], vis[maxn], vis2[maxn];
string s, s1;

int main () {
    ll ans = 0ll;
    int T, n, m, k, x, y;
    cin >> n >> s;
    s1 = s;
    for (int i = 0; i < n; i++) vis2[i] = -1;
    sort(s1.begin(), s1.end());
    bool flag = 1;
    for1(i, 0, n) {
        if (s1[i] != s[i]) {
            flag = 0;
            for1(j, i + 1, n) {
                if (s[j] == s1[i]) {
                    if (vis2[j] == -1) {
                        if (vis2[i] == -1) {
                            vis2[j] = 0;
                            vis2[i] = 1;
                            vis[j] = 1;
                            vis[i] = 0;
                        } else if (vis2[i] == 0) {
                            vis2[j] = 0;
                            vis2[i] = 1;
                            vis[j] = 1;
                        }
                        else {
                            vis2[j] = 1;
                            vis2[i] = 0;
                            vis[j] = 0;
                        }
                        swap(s[j], s[i]);
                        flag = 1;
                    } else if (vis2[j] == 0) {
                        if (vis2[i] == -1) {
                            vis[i] = 1;
                            vis2[i] = 0;
                            vis2[j] = 1;
                            swap(s[j], s[i]);
                            flag = 1;
                        } else if(vis2[i] == 1){
                            vis2[i] = 0;
                            vis2[j] = 1;
                            swap(s[i], s[j]);
                            flag = 1;
                        }
                        else continue;
                    }
                    else {
                        if(vis2[i] == -1) {
                            vis2[i] = 1;
                            vis2[j] = 0;
                            vis[i] = 0;
                            swap(s[i], s[j]);
                            flag = 1;
                        }
                        else if(vis2[i] == 0) {
                            vis2[i] = 1;
                            vis2[j] = 0;
                            swap(s[i], s[j]);
                            flag = 1;
                        }
                        else continue;
                    }
                }
                else {
                    if(vis2[j] == -1) {
                        if(vis2[i] == -1) vis2[j] = 0;
                        else if(vis2[i] == 0) vis2[j] = 0;
                        else {
                            vis2[j] = 1;
                        }
                    }
                }
                if(flag == 1) break;
            }
            if (flag == 0) break;
        }
    }
    pu;
    if (flag) {
        for1(i, 0, n) {
            // if(vis[i] == -1) vis[i] = 0;
            cout << vis[i];
        }
        cout << '\n';
    }
    return 0;
}
