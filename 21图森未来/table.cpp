#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false)
string s1, s2;
const int MAX = 105 + 5;

int prime[MAX], vis[MAX], num[MAX], cnt;
void find_prime() {
  for (int i = 2; i <= MAX; i++) {
    if (!vis[i]) prime[cnt++] = i;
    num[i] = cnt;
    for (int j = 0; j < cnt && prime[j] * i <= MAX; j++) {
      if (i % prime[j] == 0) break;
      vis[i * prime[j]] = 1;
    }
  }
}

int main() {
  cnt = 0;
  find_prime();
  int l, k;
  scanf("%d %d", &l, &k);
  if (l > 3 && k >= 3) {
    puts("No");
  } else {
    if (l <= 3) {
      if (k > 10)
        puts("No");
      else {
        if (num[l + k * 2 - 1] - num[l - 1] > k)
          puts("Yes");
        else
          puts("No");
      }
    } else
      puts("No");
  }
}