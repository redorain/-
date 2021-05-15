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
 
string s[3], temp;
int ne[5005];
int n, m;
 
void getnex(string b) {
//  for1(i, 0, m + 3)  ne[i] = 0;
    int i = 0, j = -1;
    ne[0] = -1;
    while(i < m) {
        while(j != -1 && b[j] != b[i]) j = ne[j];
        if(b[++i] == b[++j]) ne[i] = ne[j];
        else ne[i] = j;
    }
}
//
//void getnex(string b) {
//  int i = 0, j = -1;
//  ne[0] = -1;
//  while(i < m) {
//      if(j == - 1 || b[i] == b[j]) ne[++i] = ++j;
//      else j = ne[j];
//  }
//}
 
//void getnex(string b) {
//  for1(i, 0, m) ne[i] = 0;
//  ne[0] = -1;
//  for1(i, 1, m) {
//      int j = ne[i - 1];
//      while(j >= 0 && b[i] != b[j + 1]) j = ne[j];
//      if(b[i] == b[j + 1]) ++j;
//      ne[i] = j;
//  }
//}
 
//int kmp(string a, string b) {
//  cout << a << '\n' << b << '\n';
//  cout << n << ' ' << m << '\n';
//  getnex(b);
//  int j = -1;
//  for1(i, 0, n) {
//      while(j >= 0 && a[i] != b[j + 1]) j = ne[j];
//      if(a[i] == b[j + 1]) ++j;
//      if(j == m - 1)
//          return i - j + 1;
//  }
//  return -1;
//}
 
int kmp(string a, string b) {
//      cout << a << '\n' << b << '\n';
//  cout << n << ' ' << m << '\n';
    getnex(b);
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(j == -1 || a[i] == b[j]) ++i, ++j;
        else j = ne[j];
    }
    if(j == m) return i - m;
    else return -1;
}
 
int main () {
    int T, k, x, y;
    for1(i, 0, 3) cin >> s[i];
    s[0] += s[0];
    s[1] += s[1];
    int len1 = s[0].size(), len2 = s[2].size();
    m = len2, n = len1;
    x = INF;
    for (int i = 0; i + len2 < len1; i++) {
        bool flag = 1;
        temp.clear();
        for1(j, 0, len2) {
            if (s[0][i + j] == s[2][j]) {
                flag = 0;
                break;
            } else {
                if (s[0][i + j] == 'A') {
                    if (s[2][j] == 'B') temp += 'C';
                    else temp += 'B';
                } else if (s[0][i + j] == 'B') {
                    if (s[2][j] == 'A') temp += 'C';
                    else temp += 'A';
                } else {
                    if (s[2][j] == 'A') temp += 'B';
                    else temp += 'A';
                }
            }
        }
        if (flag == 1) {
            flag = 1;
            int now = kmp(s[1], temp);
            if (now != -1) {
                int n1 = i, n2 = len2 - i, n3 = now, n4 = len2 - n3;
                int s1 = n1 + n3 - min(n1, n3);
                x = min(s1, x);
                int s2 = n2 + n4 - min(n2, n4);
                x = min(s2, x);
                int s3 = n1 + n4, s4 = n2 + n3;
                x = min(s3, x);
                x = min(s4, x);
//              cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << '\n';
                // cout << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << '\n';
            }
        }
    }
    if (x == INF) cout << "-1" << '\n';
    else cout << x << '\n';
    return 0;
}