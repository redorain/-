#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int ch[maxn][30], sz, val[maxn];
char s[maxn];
string ss, no;

int getid(char s) {
    return s - 'a';
}

void init() {
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
    memset(val, INF, sizeof(val));
}

void add(char *s) {
    int now, pre = 0;
    int n = strlen(s);
    val[0] = min(val[0], n);
    for (int i = n - 1; i >= 0; i--) {
        int id = getid(s[i]);
        now = ch[pre][id];
        if (!now) {
            ch[pre][id] = sz;
            val[sz] = min(val[sz], i);
            sz++;
            memset(ch[sz], 0, sizeof(ch[sz]));
        }
        pre = now;
        val[now] = min(val[now], i);
    }
}

int find(string s) {
    int ret = val[0], n = s.size(), pre = 0, now;
    for (int i = n - 1; i >= 0; i--) {
        int id = getid(s[i]);
        now = ch[pre][id];
        if (!now) break;
        ret = min(ret, val[now]);
        pre = now;
    }
    return ret;
}

int main() {
    int n;
    init();
    cin >>  n;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        add(s);
    }
    no.clear();
    cin >> ss;
    cout << sz << '\n';
    cout << find(no) << '\n';
    int m = ss.size();
    for (int i = 0; i < m; i++) {
        if (ss[i] == '-') {
            int z = no.size();
            if (z == 0) continue;
            else {
                no.erase(z - 1);
            }
        }
        else no += ss[i];
        cout << find(no) << '\n';
    }
    return 0;
}