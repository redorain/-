#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false)
string s1, s2;

int main() {
  IO;
  cin >> s1 >> s2;
  int m = s1.size(), n = s2.size();
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    int temp = s1.find(s2[i]);
    if (s1.size() == 0 || temp == s1.npos) {
      flag = 0;
      break;
    }
    s1.erase(0, temp + 1);
  }
  puts(flag ? "Yes" : "No");
}