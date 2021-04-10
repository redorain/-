#include<bits/stdc++.h>
using namespace std;
 
//#define ll long long
 
string s;
int n, k;
const int maxn = 1e6 + 5;
const int maxm = 1e7 + 5;
int a[maxn], b[maxn], ans[maxn];
class segment_tree{public:
    #define nd node[now]
    #define ndl node[now << 1]
    #define ndr node[now << 1 | 1]
     
    struct segment_node {
        int l, r, ma;
    }node[maxm];
     
    void pushup(int now) {
        nd.ma = max(ndl.ma, ndr.ma);
    }
     
    void maketree(int l, int r, int now = 1) {
        nd = {l, r, 0};
        if(l == r) {
            nd.ma = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        maketree(l, mid, now << 1);
        maketree(mid + 1, r, now << 1 | 1);
        pushup(now);
    }
     
    void update(int pos, int val, int now = 1) {
        if(nd.l == nd.r) {
            nd.ma = val;
            return ;
        }
        if(pos <= ndl.r) update(pos, val, now << 1);
        else update(pos, val, now << 1 | 1);
        pushup(now);
    }
     
    int query(int l, int r, int now = 1) {
        if(l > r) return 0;
        if(l <= nd.l && r >= nd.r) return nd.ma;
        int ret = 0;
        if(l <= ndl.r) ret = max(ret, query(l, r, now << 1));
        if(r >= ndr.l) ret = max(ret, query(l, r, now << 1 | 1));
        return ret;
    }
}tree;
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        tree.maketree(1, n);
        int aans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            ans[b[i]] = tree.query(b[i] + 1, n) + 1;
            tree.update(b[i], ans[b[i]]);
            aans = max(aans, ans[b[i]]);
        }
        cout << aans << '\n';
        for(int i = 1; i <= n; i++) {
            cout << ans[b[i]] << ((i == n) ? '\n' : ' ');
        }
    }
 
}