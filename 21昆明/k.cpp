#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
#define ll long long
#define IO ios::sync_with_stdio(false)
const int MOD = 1e9 + 7;
int a[maxn], b[maxn];
int ans[maxn], cnt, nn, N;

struct node {
    int su;
    int num;
    bool operator < (const node y) const {
        if (su == y.su) {
            return num < y.num;
        } else {
            return su < y.su;
        }
    }
    bool operator == (const node y) const {
        if (su == y.su && num == y.num) return 1;
        else return 0;
    }
} t[105], tt[105], t3[105], need[105], th[105];

int gt(int x) {
    node no = {0, 0};
    bool flag = 0;
    int j = x + 1;
    while (j < nn) {
        if (t[j] == no) {
            j++;
        } else {
            flag = 1;
            break;
        }
    }
    if (flag) return j;
    else return -1;
}

string s, ss;

int main () {
    IO;
    ll ans = 0ll;
    int T, k, x, y;
    cin >> T;
    node no = {0, 0};
    string temp;
    while (T--) {
        cin >> s;
        int n = s.size(), m = n / 2; nn = 0, N = 0;
        temp.clear(), ss.clear();
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                t[i / 2].num = ss[i] - '0';
            else {
                int ty;
                if (s[i] == 'w') ty = 1;
                else if (s[i] == 'b') ty = 2;
                else if (s[i] == 's') ty = 3;
                else ty = 4;
                t[i / 2].su = ty;
            }
        }
        sort(t, t + m);
        for (int i = 0; i < m; i++) {
            if (t[i] == t[i + 1] && t[i + 1] == t[i + 2]) {
                cnt++;
                i += 2;
                continue;
            }
            tt[nn++] = t[i];
        }
        int n1 = 0, n2 = 0, n3 = 0, st1, st2;
        for (int i = 0; i + 2 < nn; i++) {
            if (tt[i] == no) continue;
            if (tt[i] == tt[i + 1]) st1 = gt(i + 1), st2 = gt(st1);
            else st1 = gt(i), st2 = gt(st1);
            if (st1 && st2 && tt[st1] == tt[st1 + 1]) st2 = gt(st1 + 1);
            if (st1 && st2 && tt[i].su != 4 && tt[i].num + 1 == tt[st1].num && tt[st1].num + 1 == tt[st2].num && tt[i].su == tt[st1].su && tt[st1].su == tt[st2].su) {
                tt[st1] = no;
                tt[st2] = no;
                cnt++;
                continue;
            }
            t3[N++] = tt[i];
        }
        int cnt2 = 0; int ans1 = 0;
        for (int i = 1; i < N; i++) {
            if(t3[i] == t3[i - 1]) {
                need[ans1++] = t3[i];
                ++i;
            }
        }
        if(N == 2 && cnt == 4 && ans == 1) {
            cout << "Tsumo!" << '\n';
            continue;
        }
    }
    return 0;
}
