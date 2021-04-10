#include<bits/stdc++.h>
using namespace std;
 
#define pb(a) push_back(a)
 
int a[100005];
vector<int> v[100005];
int vis[100005], num = 0, ans1 = 0, ans[100005];
 
int main(void) {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        if(a[i] == i) {
            vis[i] = 1;
            continue;
        }
        num++;
        v[num].pb(i);
        vis[i] = 1;
        int now = a[i];
        while(!vis[now]) {
            v[num].pb(now);
            vis[now] = 1;
            now = a[now];
        }
        if(v[num].size() == 2) ans1 = max(ans1, 1);
        else ans1 = max(ans1, 2);
    }
    cout << ans1 << '\n';
    for(int i = 1; i <= ans1; i++) {
        int k = 0;
        if(i == 1) {
            for(int j = 1; j <= num; j++) {
                int x = v[j].size();
                if(v[j].size() == 2) {
                    k++;
                    ans[k * 2 - 1] = v[j][0];
                    ans[k * 2] = v[j][1];
                }else {
                    int len = (x - 1) / 2;
                    for(int ii = 0; ii < len; ii++) {
                        int l = 1 + ii, r = x - 1 - ii;
                        k++;
                        ans[k * 2 - 1] = v[j][l];
                        ans[k * 2] = v[j][r];
                        swap(v[j][l], v[j][r]);
                    }
                }
            }
        }else {
            for(int j = 1; j <= num; j++) {
                int x = v[j].size();
                if(v[j].size() > 2) {
                    int len = x / 2;
                    for(int ii = 0; ii < len; ii++) {
                        k++;
                        int l = 0 + ii, r = x - 1 - ii;
                        ans[k * 2 - 1] = v[j][l];
                        ans[k * 2] = v[j][r];
                    }
                }
            }
        }
        cout << k;
        int len = k * 2;
        for(int j = 1; j <= len; j++) cout << ' ' << ans[j];cout << '\n';
    }
}