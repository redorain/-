#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int b[maxn], vis[maxn];

priority_queue<int> q[maxn];
struct node {

    int val;
    bool operator<(const node y) const {
        return val > y.val;
    }
} a[maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].val++;
        a[y].val++;
        q[x].push(a[y].val);
        q[y].push(a[x].val);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        else {
            vis[i] = 1;
            int temp = q[i].top();
            while (vis[temp] == 1 && q[i].empty() == 0) {
                q[i].pop();
                temp = q[i].top();
            }
            if (vis[temp] == 0)
                ans++, vis[temp] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}