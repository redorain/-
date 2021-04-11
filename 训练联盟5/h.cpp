#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
#define ll long long
struct node {
  ll num, len;
  string s;
} a[maxn];

int main() {
  int n;
  ios::sync_with_stdio(false);
  cin >> n;
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i].s;
    a[i].len = a[i].s.size();
    if (!flag) continue;
    if (i == 0) {
      for (int j = 0; j < a[i].len; j++)
        if (a[i].s[j] == '9') a[i].s[j] = '6';
    } else {
      if (a[i].len < a[i - 1].len) {
        flag = 0;
        continue;
      } else if (a[i].len > a[i - 1].len) {
        for (int j = 0; j < a[i].len; j++)
          if (a[i].s[j] == '9') a[i].s[j] = '6';
        continue;
      } else {
        int pos = -1;
        for (int j = 0; j < a[i].len; j++) {
          if (a[i].s[j] == a[i - 1].s[j]) {
            if (a[i].s[j] == '6') pos = j;
          } else {
            if (a[i].s[j] > a[i - 1].s[j]) {
              if (a[i].s[j] == '9' && a[i - 1].s[j] == '6') {
                a[i].s[j] = '6';
                pos = j;
                continue;
              }
              if(a[i].s[j] == '9' && a[i - 1].s[j] < '6') a[i].s[j] = '6';
              for (int k = j + 1; k < a[i].len; k++)
                if (a[i].s[k] == '9') a[i].s[k] = '6';
              break;
            } else {
              if (a[i].s[j] == '6' && a[i - 1].s[j] == '9') {
                a[i].s[j] = '9';
              } else if (a[i].s[j] == '6' && a[i - 1].s[j] != '9') {
                a[i].s[j] = '9';
                for (int k = j + 1; k < a[i].len; k++)
                  if (a[i].s[k] == '9') a[i].s[k] = '6';
                break;
              } else {
                if (pos != -1) {
                  a[i].s[pos] = '9';
                  for (int k = j + 1; k < a[i].len; k++)
                    if (a[i].s[k] == '9') a[i].s[k] = '6';
                  break;
                } else {
                  flag = 0;
                  break;
                }
              }
            }
          }
        }
      }
    }
  }
  if (flag) {
    cout << "possible" << '\n';
    for (int i = 0; i < n; i++) cout << a[i].s << '\n';
  } else {
    cout << "impossible" << '\n';
  }
  return 0;
}