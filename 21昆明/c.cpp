#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], dp[5005][5005], pre[maxn], las[maxn];

int main() {
    int T, n, x;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int cnt = 1;
        for (int i = 0; i < n; i++) {
             scanf("%d", &x);
            las[i] = pre[i] = 0;
            if (i == 0) a[cnt++] = x;
            else if (x != a[cnt - 1])
                a[cnt++] = x;
        }
        for(int i = 1; i <= cnt; i++) pre[i] = las[a[i]], las[a[i]] = i, dp[i][i] = 0;
        for (int i = 1; i < cnt - 1; i++) {
            for (int j = 1; j + i < cnt; j++) {
                if (a[j + i] == a[j])
                    dp[j][j + i] = min(dp[j + 1][j + i], min(dp[j][j + i - 1], dp[j + 1][j + i - 1] + 1));
                else dp[j][j + i] = min(dp[j + 1][j + i], min(dp[j][j + i - 1], dp[j + 1][j + i - 1] + 1)) + 1;
                for(int k = pre[j + i]; k > j; k = pre[k]) {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][k - 1] + dp[k][j + i] + 1);
                }
                // cout << j << " " << j + i << ':' << " " << dp[j][j + i]<< " " << dp[j + 1][j + i]<< " " << dp[j][j + i - 1] << " " << dp[j + 1][j + i - 1]<< '\n';
            }

        }
        printf("%d\n", dp[1][cnt - 1]);
    }
    return 0;
}
